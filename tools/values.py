#!/usr/bin/env python3
"""Find hex literals that should be decimal quantities, and rewrite them.

    tools/values.py fields [--write] [PATH...]               coordinates and primitive macros
    tools/values.py compare --names a,b,c [--write] [PATH...]  comparisons with named quantities

The convention is decimal for quantities and hex for bit patterns
([conventions](docs/conventions.md#types-and-values)). `fields` converts hex literals assigned to
`.x .y .w .h .u0-.u3 .v0-.v3` members and passed to the `setXY*`, `setWH`, `setUV*`, `setRGB*`,
`setRECT`, `GetClut` and `GetTPage` macros, except next to a bitwise operator or above 0x7FFFFFFF.
`compare` converts `name < 0x64` style tests of the variables you name, up to 0xFFFF.

With no PATH the tracked C files under `src/` are read. Without --write the tool prints each
line it would change and changes nothing. Review the lines first: a byte offset or an address
stays hex ([conventions](docs/conventions.md#types-and-values)). Decimal and hex spell the same bytes: run
`meson compile -C build/meson check` after --write.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path

from bof3.source import ctext

ROOT = Path(__file__).resolve().parent.parent
HEX = re.compile(r"([<>&|^~]=?\s*)?\b0[xX]([0-9A-Fa-f]+)([uUlL]*)\b(\s*[&|^])?")
FIELD = re.compile(r"^(.*?(?:\.|->)(?:x|y|w|h|[xyuv][0-3])\s*=\s*)([^;]*;.*)$", re.S)
MACRO = re.compile(
    r"^(.*?\b(?:setXY\d|setWH|setUV\d|setXYWH|setRECT|setRGB\d|GetClut|GetTPage)\()(.*)$",
    re.S,
)
EXCLUDED = re.compile(r"\b(?:pad|flag|mask)\b", re.I)


def decimal(text: str) -> str:
    """Convert the hex literals of ``text`` that are not bitwise operands."""

    def one(m: re.Match[str]) -> str:
        before, digits, suffix, after = m.groups()
        value = int(digits, 16)
        if before or after or value > 0x7FFFFFFF:
            return m.group(0)
        return f"{value}{suffix}"

    return HEX.sub(one, text)


def decimalize_fields(text: str) -> str:
    """Rewrite member assignments and primitive macros line by line."""
    out = []
    for line in text.splitlines(keepends=True):
        field = FIELD.match(line)
        if field and not EXCLUDED.search(line):
            line = field[1] + decimal(field[2])
        elif not field:
            macro = MACRO.match(line)
            if macro:
                line = macro[1] + decimal(macro[2])
        out.append(line)
    return "".join(out)


def decimalize_compares(text: str, names: list[str]) -> str:
    """Rewrite ``name <op> 0xNN`` tests of the named variables."""
    pattern = re.compile(
        r"(?<![\w>&|^<~.])((?:"
        + "|".join(map(re.escape, names))
        + r")(?:\[[^\]]*\])?)(\s*)"
        r"((?<![<>])(?:<=?|>=?|==|!=)(?![<>=]))(\s*)(-?)0[xX]([0-9A-Fa-f]+)(u?)\b"
    )

    def one(m: re.Match[str]) -> str:
        value = int(m[6], 16)
        if value > 0xFFFF:
            return m.group(0)
        return f"{m[1]}{m[2]}{m[3]}{m[4]}{m[5]}{value}{m[7]}"

    return pattern.sub(one, text)


def main(argv: list[str] | None = None) -> int:
    """Run one verb over the files."""
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    verbs = parser.add_subparsers(dest="verb", required=True)
    for name in ("fields", "compare"):
        verb = verbs.add_parser(name)
        if name == "compare":
            verb.add_argument(
                "--names", required=True, help="comma-separated variable names"
            )
        verb.add_argument("--write", action="store_true", help="change the files")
        verb.add_argument("paths", nargs="*", help="files or folders (default: src)")
    args = parser.parse_args(argv)
    names = args.names.split(",") if args.verb == "compare" else []
    prefixes = tuple(Path(p).as_posix().rstrip("/") for p in args.paths) or ("src",)
    changed = 0
    for name in ctext.tracked(ROOT, *prefixes):
        if not name.endswith((".c", ".h")):
            continue
        text = ctext.read(ROOT, name)
        new = (
            decimalize_fields(text)
            if args.verb == "fields"
            else decimalize_compares(text, names)
        )
        if new != text:
            changed += 1
            for number, (a, b) in enumerate(
                zip(text.splitlines(), new.splitlines()), 1
            ):
                if a != b:
                    print(
                        f"{name}:{number}: {a.strip()}\n{' ' * len(name)}  -> {b.strip()}"
                    )
            if args.write:
                (ROOT / name).write_text(new, encoding="utf-8")
    return 0 if args.write or not changed else 1


if __name__ == "__main__":
    raise SystemExit(main())
