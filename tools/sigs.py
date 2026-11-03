#!/usr/bin/env python3
"""Compare prototypes, definitions and calls across the C tree.

    tools/sigs.py scan [--kind KIND] [PATH...]   one row per problem, counts on stderr
    tools/sigs.py cross                          prototypes that differ from a definition in
                                                 another file, as name, proto, line, def, why
    tools/sigs.py implicit                       implicit declarations by callee: does every
                                                 translation unit already see a prototype?
    tools/sigs.py sync < cross-rows              rewrite each prototype listed on stdin (the
                                                 output of `cross`) to its definition's signature
    tools/sigs.py uncast NAME FILE...            replace ((T (*)(args))NAME)( with NAME(

`scan` kinds: ret_mismatch, argc_mismatch, argtype_mismatch, proto_unspecified_args,
param_name_differs, proto_placeholder_name, def_placeholder_name, implicit_decl, call_argc,
call_through_cast, return_cast, void_result_read, wide_ret_all_callers_cast.

Every edit is a lead: run `meson compile -C build/meson check` after `sync` or `uncast`.
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

from bof3.source import ctext, decls

ROOT = Path(__file__).resolve().parent.parent


def load_tree() -> decls.Tree:
    """Read every tracked C file under ``src/`` and ``include/``."""
    return decls.Tree({name: ctext.read(ROOT, name) for name in ctext.tracked_c(ROOT)})


def scan(args: argparse.Namespace) -> int:
    """Print one tab-separated row per problem."""
    rows = decls.problems(load_tree())
    prefixes = tuple(args.paths)
    counts: collections.Counter[str] = collections.Counter()
    for row in rows:
        if args.kind and row.kind not in args.kind:
            continue
        if prefixes and not row.file.startswith(prefixes):
            continue
        counts[row.kind] += 1
        print(row.kind, row.name, row.file, row.line, row.detail, sep="\t")
    for kind, count in sorted(counts.items()):
        print(f"{kind}\t{count}", file=sys.stderr)
    return 0


def cross(_args: argparse.Namespace) -> int:
    """Print prototypes that disagree with a definition elsewhere."""
    for name, proto, definition, why in decls.cross_image(load_tree()):
        print(name, proto.file, proto.line, definition.file, why, sep="\t")
    return 0


def implicit(_args: argparse.Namespace) -> int:
    """Summarise implicit declarations by callee."""
    tree = load_tree()
    rows = decls.implicit_coverage(tree, decls.problems(tree))
    by_name: dict[str, collections.Counter[str]] = collections.defaultdict(
        collections.Counter
    )
    for name, _file, _line, units, bad in rows:
        by_name[name]["real" if bad else "covered" if units else "no unit"] += 1
    for name, kinds in sorted(by_name.items(), key=lambda item: -item[1]["real"]):
        print(
            name,
            *(f"{kind}={count}" for kind, count in sorted(kinds.items())),
            sep="\t",
        )
    return 0


def signature(name: str, definition: decls.Decl) -> str | None:
    """Return the prototype statement of ``definition``, or None for a function-pointer parameter."""
    params = []
    for ptype, pname in definition.params:
        if "(" in ptype or ptype == "...":
            return None
        params.append(f"{ptype} {pname}" if pname else ptype)
    return f"{definition.ret} {name}({', '.join(params) or 'void'});"


def sync(_args: argparse.Namespace) -> int:
    """Rewrite the prototypes named on stdin to their definition's signature."""
    tree = load_tree()
    definitions = {
        (name, d.file): d
        for name, ds in tree.decls.items()
        for d in ds
        if d.kind == "def"
    }
    edited: set[str] = set()
    for row in sys.stdin:
        name, proto_file, _line, def_file, *_ = row.rstrip("\n").split("\t")
        definition = definitions.get((name, def_file))
        statement = signature(name, definition) if definition else None
        if statement is None:
            print(f"skip {name} {proto_file}", file=sys.stderr)
            continue
        text = ctext.read(ROOT, proto_file)
        pattern = re.compile(
            r"^((?:extern\s+)?)([A-Za-z_][\w \t\*]*?[\s\*])"
            + re.escape(name)
            + r"\s*\([^;{}]*\)\s*;",
            re.M,
        )
        found = pattern.search(text)
        if not found or re.search(r"\b(static|MATCH|INLINE)\b", found.group(2)):
            print(f"nomatch {name} {proto_file}", file=sys.stderr)
            continue
        text = text[: found.start()] + found.group(1) + statement + text[found.end() :]
        (ROOT / proto_file).write_text(text, encoding="utf-8")
        edited.add(proto_file)
    print("\n".join(sorted(edited)))
    return 0


def uncast(args: argparse.Namespace) -> int:
    """Replace call-through casts of one function."""
    pattern = re.compile(
        r"\(\(\s*[^()]*?\(\s*\*\s*\)\s*\([^()]*\)\s*\)\s*"
        + re.escape(args.name)
        + r"\s*\)\s*\("
    )
    for file in args.files:
        path = ROOT / file
        text, count = pattern.subn(args.name + "(", path.read_text(encoding="utf-8"))
        if count:
            path.write_text(text, encoding="utf-8")
            print(file, count)
    return 0


def main(argv: list[str] | None = None) -> int:
    """Run one verb."""
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    verbs = parser.add_subparsers(dest="verb", required=True)
    one = verbs.add_parser("scan", help="list problems")
    one.add_argument("--kind", action="append", help="only this kind (repeatable)")
    one.add_argument("paths", nargs="*", help="only rows in files under these paths")
    one.set_defaults(run=scan)
    verbs.add_parser(
        "cross", help="prototype against definition in another file"
    ).set_defaults(run=cross)
    verbs.add_parser("implicit", help="implicit declarations by callee").set_defaults(
        run=implicit
    )
    verbs.add_parser(
        "sync", help="rewrite prototypes from `cross` rows on stdin"
    ).set_defaults(run=sync)
    two = verbs.add_parser("uncast", help="remove call-through casts of one function")
    two.add_argument("name")
    two.add_argument("files", nargs="+")
    two.set_defaults(run=uncast)
    args = parser.parse_args(argv)
    return args.run(args)


if __name__ == "__main__":
    raise SystemExit(main())
