#!/usr/bin/env python3
"""Find duplicate and similar functions across every built image.

    tools/dups.py near [-t 0.9] [-m 6] [-o FILE]   groups of functions with alike opcodes,
                                                   and the matched template of each assembly one
    tools/dups.py shared-names                     one name used in several places, worst first
    tools/dups.py split-names                      byte-equal bodies that carry several names

Each verb prints tab-separated rows (or writes them to -o) and a summary on stderr. It reads the
function index of the built images ({cache}); run `meson compile -C build/meson` first and add
--rebuild after a build. Needs `rapidfuzz` (`tools/setup.sh --matching`). Within one image,
`bin/coddog cluster` finds duplicate groups too; this tool compares across images and names.
"""

from __future__ import annotations

import argparse
import collections
import contextlib
import itertools
import sys
from pathlib import Path

from bof3.source.index import CACHE, Func, load_index, opcode_string

ROOT = Path(__file__).resolve().parent.parent
PLACEHOLDER = ("func_", "D_", "jtbl_")


def functions(args: argparse.Namespace, min_words: int = 0) -> list[Func]:
    """Return the indexed functions, SDK code excluded."""
    return [
        f
        for f in load_index(ROOT, args.rebuild)
        if f.status != "LIB" and len(f.words) >= min_words
    ]


def emit(args: argparse.Namespace, header: list[str], rows: list[list]) -> None:
    """Write the table to ``--out`` or stdout."""
    with contextlib.ExitStack() as stack:
        out = (
            stack.enter_context(open(args.out, "w", encoding="utf-8"))
            if args.out
            else sys.stdout
        )
        print("\t".join(header), file=out)
        for row in rows:
            print("\t".join(map(str, row)), file=out)


def import_rapidfuzz():
    """Return ``rapidfuzz.process`` and ``Indel``, or exit with the install step."""
    try:
        from rapidfuzz import process
        from rapidfuzz.distance import Indel
    except ImportError:
        raise SystemExit(
            "dups: needs rapidfuzz. Run: tools/setup.sh --matching"
        ) from None
    return process, Indel


def near(args: argparse.Namespace) -> int:
    """Group functions whose opcode sequences are alike; pair assembly with a C template."""
    process, indel = import_rapidfuzz()
    funcs = functions(args, args.min_words)
    by_seq: dict[str, list[Func]] = collections.defaultdict(list)
    for f in funcs:
        by_seq[opcode_string(f.words)].append(f)
    seqs = sorted(by_seq, key=lambda s: (len(s), s))
    adjacent: list[dict[int, float]] = [{} for _ in seqs]
    for i, s in enumerate(seqs):
        for _, score, j in process.extract(
            s,
            seqs,
            scorer=indel.normalized_similarity,
            score_cutoff=args.threshold,
            limit=None,
        ):
            if j != i:
                adjacent[i][j] = float(score)
    has_c = [any(f.status == "C" for f in by_seq[s]) for s in seqs]
    order = sorted(range(len(seqs)), key=lambda i: (-len(adjacent[i]), not has_c[i], i))
    assigned: set[int] = set()
    rows = []
    for centre in order:
        if centre in assigned:
            continue
        members = [centre] + [j for j in adjacent[centre] if j not in assigned]
        assigned.update(members)
        row = near_row(by_seq, seqs, adjacent, centre, members)
        if row:
            rows.append(row)
    rows.sort(
        key=lambda r: (-r["candidate"], -r["asm_bytes"], -r["members"] * r["size_max"])
    )
    header = ["rank", "kind", "members", "byte_classes", "size_min", "size_max", "min_similarity",
              "matched", "assembly", "candidate", "asm_with_template", "asm_bytes", "templates_top4",
              "member_list"]  # fmt: skip
    emit(
        args,
        header,
        [[i, *(r[k] for k in header[1:])] for i, r in enumerate(rows, 1)],
    )
    candidates = [r for r in rows if r["candidate"]]
    print(
        f"groups {len(rows)}, with a matched and an assembly member {len(candidates)}, "
        f"assembly functions with a template {sum(r['asm_with_template'] for r in candidates)}, "
        f"their bytes {sum(r['asm_bytes'] for r in candidates)}",
        file=sys.stderr,
    )
    return 0


def near_row(by_seq, seqs, adjacent, centre, members) -> dict | None:
    """Describe one group, or None when it is only identical bodies of one kind."""
    funcs = [f for i in members for f in by_seq[seqs[i]]]
    if len(funcs) < 2:
        return None
    hashes = {f.sha1 for f in funcs}
    lifted = sum(f.status == "C" for f in funcs)
    assembly = len(funcs) - lifted
    if len(hashes) < 2 and not (lifted and assembly):
        return None
    c_members = [i for i in members if any(f.status == "C" for f in by_seq[seqs[i]])]
    templates = []
    for i in members:
        for f in (g for g in by_seq[seqs[i]] if g.status == "ASM"):
            best = None
            for j in c_members:
                sim = 1.0 if j == i else adjacent[i].get(j)
                if sim is not None and (best is None or sim > best[0]):
                    best = (sim, j)
            if best:
                template = next(g for g in by_seq[seqs[best[1]]] if g.status == "C")
                templates.append((f, template, best[0]))
    templates.sort(key=lambda t: (-t[2], -t[0].size))
    sims = [1.0 if i == centre else adjacent[centre][i] for i in members]
    sizes = [f.size for f in funcs]
    listing = [
        f"{f.image}:{f.name}:{f.status}"
        for f in sorted(funcs, key=lambda f: (f.image, f.addr))
    ]
    return {
        "kind": "opcode-equal" if len({seqs[i] for i in members}) == 1 else "similar",
        "members": len(funcs),
        "byte_classes": len(hashes),
        "size_min": min(sizes),
        "size_max": max(sizes),
        "min_similarity": f"{min(sims):.3f}",
        "matched": lifted,
        "assembly": assembly,
        "candidate": int(bool(lifted and assembly)),
        "asm_with_template": len(templates),
        "asm_bytes": sum(f.size for f, _, _ in templates),
        "templates_top4": " ; ".join(
            f"{a.image}:{a.name}<-{b.image}:{b.name}@{s:.3f}"
            for a, b, s in templates[:4]
        ),
        "member_list": " | ".join(listing[:25])
        + (f" | +{len(listing) - 25} more" if len(listing) > 25 else ""),
    }


def shared_names(args: argparse.Namespace) -> int:
    """List each name used in several places, with how alike the bodies are."""
    _process, indel = import_rapidfuzz()
    groups: dict[str, list[Func]] = collections.defaultdict(list)
    for f in functions(args):
        if not f.name.startswith(PLACEHOLDER):
            groups[f.name].append(f)
    rows = []
    for name, members in groups.items():
        if len(members) < 2:
            continue
        distinct = sorted({opcode_string(m.words) for m in members}, key=len)
        sim = min(
            (
                indel.normalized_similarity(a, b)
                for a, b in itertools.combinations(distinct, 2)
            ),
            default=1.0,
        )
        sizes = [m.size for m in members]
        rows.append([
            round(sim, 3), name, len(members), len({m.image for m in members}),
            len({m.sha1 for m in members}), len(distinct), min(sizes), max(sizes),
            " | ".join(m.ref for m in members[:12]),
        ])  # fmt: skip
    rows.sort(key=lambda r: (r[0], r[1]))
    emit(args, ["min_similarity", "name", "members", "images", "byte_classes", "opcode_classes",
                "size_min", "size_max", "members_first12"], rows)  # fmt: skip
    print(
        f"{len(rows)} shared names; opcode-identical {sum(r[5] == 1 for r in rows)}; "
        f"below 0.9 {sum(r[0] < 0.9 for r in rows)}",
        file=sys.stderr,
    )
    return 0


def split_names(args: argparse.Namespace) -> int:
    """List byte-equal bodies that carry more than one real name."""
    groups: dict[str, list[Func]] = collections.defaultdict(list)
    for f in functions(args, 6):
        groups[f.sha1].append(f)
    rows = []
    for members in groups.values():
        names = {m.name for m in members if not m.name.startswith(PLACEHOLDER)}
        placeholders = sum(m.name.startswith("func_") for m in members)
        if len(names) > 1 or (names and placeholders):
            rows.append([
                len(names), placeholders, len(members), members[0].size,
                " ".join(sorted(names)), " | ".join(m.ref for m in members[:10]),
            ])  # fmt: skip
    rows.sort(key=lambda r: (-r[0], -r[1]))
    emit(
        args,
        ["real_names", "placeholders", "members", "size", "names", "members_first10"],
        rows,
    )
    print(
        f"{sum(r[0] > 1 for r in rows)} bodies with several real names; "
        f"{sum(r[0] == 1 and bool(r[1]) for r in rows)} with one name and placeholder copies",
        file=sys.stderr,
    )
    return 0


def main(argv: list[str] | None = None) -> int:
    """Run one verb."""
    parser = argparse.ArgumentParser(
        description=__doc__.format(cache=CACHE),
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--rebuild", action="store_true", help="rebuild the function index first"
    )
    verbs = parser.add_subparsers(dest="verb", required=True)
    for name, run, help_text in (
        ("near", near, "alike opcode sequences with templates"),
        ("shared-names", shared_names, "one name, several bodies"),
        ("split-names", split_names, "one body, several names"),
    ):
        verb = verbs.add_parser(name, help=help_text)
        verb.add_argument("-o", "--out", help="write the table here instead of stdout")
        if name == "near":
            verb.add_argument(
                "-t", "--threshold", type=float, default=0.9, help="similarity (0.9)"
            )
            verb.add_argument(
                "-m", "--min-words", type=int, default=6, help="instructions (6)"
            )
        verb.set_defaults(run=run)
    args = parser.parse_args(argv)
    return args.run(args)


if __name__ == "__main__":
    raise SystemExit(main())
