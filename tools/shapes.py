#!/usr/bin/env python3
"""Find data that is written in the wrong shape, and rewrite text tables as string literals.

    tools/shapes.py text [PATH...]       byte arrays written as hex that hold text
    tools/shapes.py strided              byte arrays read with a stride or through a wider cast
    tools/shapes.py types                one role name declared with different types
    tools/shapes.py literal FILE NAME WIDTH COUNT TYPE [--print]
                                         rewrite NAME's hex initializer as COUNT string rows of
                                         WIDTH bytes; TYPE `u8` is game text (the T_ pieces of
                                         include/game/text.h), `char` is plain text

`text` classes: ascii-text (printable, zero-terminated), game-text? (mostly letters and the
game's control bytes), letters (a run of four letters or more), bytes. The scans read tracked
C files under `src/` and `include/`, or only the PATH prefixes. They give leads: the reader of
the array decides its type ([conventions](docs/conventions.md#types-and-values)).
"""

from __future__ import annotations

import argparse
import collections
import re
import sys
from pathlib import Path

from bof3.source import ctext

ROOT = Path(__file__).resolve().parent.parent
BYTE_ARRAY = re.compile(
    r"^\s*(?:static\s+)?(?:const\s+)?(?:volatile\s+)?(u8|s8|char|unsigned char)\s+(\w+)\s*"
    r"((?:\[[^\]]*\])*)\s*=\s*\{(.*?)\};",
    re.S | re.M,
)
NUMBER = re.compile(r"0x[0-9A-Fa-f]+|-?\b\d+\b")
PIECE = re.compile(r'^#define\s+(T_\w+)\s+"\\x([0-9A-Fa-f]{2})"', re.M)


def load(prefixes: tuple[str, ...] = ()) -> dict[str, str]:
    """Read the tracked C files, optionally only under ``prefixes``."""
    names = [n for n in ctext.tracked_c(ROOT) if not prefixes or n.startswith(prefixes)]
    return {n: ctext.read(ROOT, n) for n in names}


def numbers(body: str) -> bytes | None:
    """Return the initializer as bytes, or None when it holds a symbol or an expression."""
    items = [x.strip() for x in body.replace("\n", " ").split(",") if x.strip()]
    if not all(re.fullmatch(r"-?(0x[0-9A-Fa-f]+|\d+)u?", x) for x in items):
        return None
    return bytes(int(x.rstrip("u"), 0) & 255 for x in items)


def classify(data: bytes) -> str:
    """Name what a byte string looks like."""
    letters = sum(chr(b).isalpha() and b < 0x7F for b in data)
    printable = sum(0x20 <= b < 0x7F or b == 0 for b in data)
    if data[-1:] == b"\0" and printable == len(data) and letters >= len(data) * 0.5:
        return "ascii-text"
    game = sum(0x30 <= b < 0x7B or b in (0, 1, 2) for b in data)
    if game >= len(data) * 0.8 and 0 in data and letters >= len(data) * 0.4:
        return "game-text?"
    if re.search(rb"[A-Za-z]{4,}", data):
        return "letters"
    return "bytes"


def text(args: argparse.Namespace) -> int:
    """List hex byte arrays that look like text."""
    counts: collections.Counter[str] = collections.Counter()
    for name, source in load(tuple(args.paths)).items():
        for m in BYTE_ARRAY.finditer(source):
            data = numbers(m.group(4))
            if data is None or len(data) < 4:
                continue
            kind = classify(data)
            counts[kind] += 1
            if kind != "bytes":
                preview = bytes(
                    b if 0x20 <= b < 0x7F else 0x2E for b in data[:40]
                ).decode()
                print(
                    kind,
                    f"{name}:{m.group(2)}{m.group(3)}",
                    len(data),
                    preview,
                    sep="\t",
                )
    for kind, count in sorted(counts.items()):
        print(f"{kind}\t{count}", file=sys.stderr)
    return 0


def strided(_args: argparse.Namespace) -> int:
    """List byte arrays that code indexes with a stride or reads through a wider type."""
    texts = load()
    decl = re.compile(
        r"^\s*(?:static\s+)?(?:const\s+)?(u8|s8)\s+(\w+)\s*\[([^\]]*)\]\s*=\s*\{", re.M
    )
    arrays = {
        m.group(2): (name, m.group(3))
        for name, t in texts.items()
        for m in decl.finditer(t)
    }
    use = re.compile(
        r"(\(\s*\w+\s*\*\s*\)\s*&?\s*)?\b(" + "|".join(map(re.escape, arrays)) + r")\b"
        r"(\s*\[[^\]]*\])?(\s*\+\s*[^;,)]+)?"
    )
    uses: dict[str, list[str]] = collections.defaultdict(list)
    for m in use.finditer("\n".join(texts.values())):
        uses[m.group(2)].append(m.group(0))
    stride_re = re.compile(r"\*\s*(0x[0-9A-Fa-f]+|\d+)|(0x[0-9A-Fa-f]+|\d+)\s*\*")
    cast_re = re.compile(r"\(\s*\w+\s*\*\s*\)")
    counts: collections.Counter[str] = collections.Counter()
    for name, (file, dim) in sorted(arrays.items()):
        found = uses[name][1:]  # the first occurrence is the declaration
        if not found:
            counts["unused"] += 1
            continue
        stride = [u for u in found if stride_re.search(u)]
        cast = [u for u in found if cast_re.match(u)]
        kind = "stride" if stride else "cast" if cast else "plain"
        counts[kind] += 1
        if kind != "plain":
            print(kind, file, name, dim, (stride or cast)[0][:70], sep="\t")
    for kind, count in sorted(counts.items()):
        print(f"{kind}\t{count}", file=sys.stderr)
    return 0


def types(_args: argparse.Namespace) -> int:
    """List names declared with more than one type, or as both array and scalar."""
    decl = re.compile(
        r"^(?:extern\s+|static\s+)?((?:const\s+|volatile\s+)*(?:struct\s+)?[A-Za-z_]\w*(?:\s*\*+)?)\s+"
        r"(\*?)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(?:=|;)",
        re.M,
    )
    skip = {
        "return",
        "typedef",
        "else",
        "goto",
        "case",
        "struct",
        "union",
        "enum",
        "void",
        "define",
    }
    seen: dict[str, set[tuple[str, str, str]]] = collections.defaultdict(set)
    for file, source in load().items():
        for m in decl.finditer(source):
            kind = " ".join(
                re.sub(r"\b(extern|static|const|volatile)\b", "", m.group(1)).split()
            ) + m.group(2)
            if kind.split()[0] in skip or m.group(3).startswith("D_"):
                continue
            seen[m.group(3)].add((kind, "array" if m.group(4) else "scalar", file))
    total = 0
    for name, entries in sorted(seen.items()):
        shapes = {(t, a) for t, a, _ in entries}
        if len({t for t, _ in shapes}) > 1:
            total += 1
            print(name, sorted(shapes), len(entries), sep="\t")
    print(f"total\t{total}", file=sys.stderr)
    return 0


def literal_of(data: bytes, game: bool, pieces: dict[int, str]) -> str:
    """Return the bytes as adjacent C string literals and T_ pieces (trailing zeros dropped)."""
    out, current = [], ""
    for b in data.rstrip(b"\0"):
        if (chr(b).isalnum() and b < 0x7F) or (
            not game and 0x20 <= b < 0x7F and chr(b) not in '"\\'
        ):
            current += chr(b)
            continue
        if current:
            out.append(f'"{current}"')
            current = ""
        out.append(pieces[b] if game and b in pieces and b != 0 else f'"\\x{b:02X}"')
    if current:
        out.append(f'"{current}"')
    return " ".join(out) or '""'


def literal(args: argparse.Namespace) -> int:
    """Rewrite one array's initializer as string rows."""
    game = args.type == "u8"
    pieces = {
        int(h, 16): n for n, h in PIECE.findall(ctext.read(ROOT, "include/game/text.h"))
    }
    path = ROOT / args.file
    source = path.read_text(encoding="utf-8")
    m = re.search(
        r"((?:static )?)(?:const )?\w+ "
        + re.escape(args.name)
        + r"\[[^\]]*\] = \{(.*?)\};",
        source,
        re.S,
    )
    if not m:
        raise SystemExit(f"shapes: no hex initializer of {args.name} in {args.file}")
    data = bytes(int(x, 0) for x in NUMBER.findall(m.group(2)))
    if len(data) != args.width * args.count:
        raise SystemExit(
            f"shapes: {args.name} holds {len(data)} bytes, not {args.width} x {args.count}"
        )
    rows = [
        literal_of(data[i * args.width : (i + 1) * args.width], game, pieces)
        for i in range(args.count)
    ]
    dims = f"[{args.count}][{args.width}]" if args.count > 1 else f"[{args.width}]"
    body = (
        "{\n" + "".join(f"    {r},\n" for r in rows) + "}"
        if args.count > 1
        else rows[0]
    )
    if args.print:
        print("\n".join(f"    {r}," for r in rows))
        return 0
    new = f"{m.group(1)}{args.type} {args.name}{dims} = {body};"
    path.write_text(source[: m.start()] + new + source[m.end() :], encoding="utf-8")
    return 0


def main(argv: list[str] | None = None) -> int:
    """Run one verb."""
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    verbs = parser.add_subparsers(dest="verb", required=True)
    one = verbs.add_parser("text", help="hex arrays that hold text")
    one.add_argument("paths", nargs="*", help="only files under these prefixes")
    one.set_defaults(run=text)
    verbs.add_parser(
        "strided", help="byte arrays read with a stride or cast"
    ).set_defaults(run=strided)
    verbs.add_parser("types", help="one role name, several types").set_defaults(
        run=types
    )
    two = verbs.add_parser("literal", help="rewrite a hex initializer as string rows")
    two.add_argument("file")
    two.add_argument("name")
    two.add_argument("width", type=int)
    two.add_argument("count", type=int)
    two.add_argument("type", choices=("u8", "char"))
    two.add_argument(
        "--print", action="store_true", help="print the rows; change nothing"
    )
    two.set_defaults(run=literal)
    args = parser.parse_args(argv)
    return args.run(args)


if __name__ == "__main__":
    raise SystemExit(main())
