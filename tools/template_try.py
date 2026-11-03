#!/usr/bin/env python3
"""Try matched C functions as the bodies of assembly functions, and keep the exact ones.

    tools/template_try.py ROWS.tsv [--dry-run]

Each row of ROWS.tsv is `TARGET@NAME`, a tab, then `TEMPLATE@NAME`: the assembly function and the
lifted function it resembles (`tools/dups.py near` and `tools/template_diff.py` find pairs). For
each row the tool replaces the target's `INCLUDE_ASM(name);` line with the template's definition
under the target's name and runs `tools/match.sh`. An exact result stays in the tree; any other
result restores the file. One line per row: `EXACT`, `FAIL` with the first difference, `SKIP` with
the reason. A row that ran stays a lead: run `meson compile -C build/meson check-<image>`, then give
the body its evidence-based name and the shared-body treatment of docs/conventions.md.
"""

from __future__ import annotations

import argparse
import re
import subprocess
from pathlib import Path

from bof3.source.ctext import find_definition, read
from bof3.source.index import find, load_index

ROOT = Path(__file__).resolve().parent.parent
QUOTED = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


def locate(
    src: str, name: str, depth: int = 3, seen: set[str] | None = None
) -> tuple[str, int, int] | None:
    """Find where ``name`` is defined for the C file ``src``, or in a header it includes."""
    seen = seen if seen is not None else set()
    if src in seen:
        return None
    seen.add(src)
    text = read(ROOT, src)
    span = find_definition(text, name)
    if span:
        return src, *span
    if depth:
        for inc in QUOTED.findall(text):
            for base in (str(Path(src).parent), "src/shared", "src", "include"):
                candidate = (Path(base) / inc).as_posix()
                if (ROOT / candidate).is_file() and candidate.startswith("src/"):
                    found = locate(candidate, name, depth - 1, seen)
                    if found:
                        return found
    return None


def match(ref: str) -> tuple[bool, str]:
    """Run ``tools/match.sh`` on one function; return (exact, last lines)."""
    target, _, name = ref.partition("@")
    result = subprocess.run(
        ["sh", "tools/match.sh", target, name],
        cwd=ROOT,
        capture_output=True,
        text=True,
        check=False,
    )
    tail = (result.stdout + result.stderr).strip().splitlines()[-3:]
    return result.returncode == 0, " | ".join(x.strip() for x in tail)[:230]


def attempt(funcs, row: str, dry: bool) -> str:
    """Try one row and return its report line."""
    target_ref, template_ref = row.split("\t")[:2]
    target, template = find(funcs, target_ref), find(funcs, template_ref)
    if target.status != "ASM" or not target.src:
        return f"SKIP {target_ref} is not an INCLUDE_ASM function"
    if template.status != "C" or not template.src:
        return f"SKIP {template_ref} is not lifted C"
    marker = f"INCLUDE_ASM({target.name});"
    text = read(ROOT, target.src)
    if marker not in text:
        return f"SKIP {target_ref} already has a body"
    where = locate(template.src, template.name)
    if where is None:
        return f"SKIP no definition of {template.name} under {template.src}"
    source, start, end = where
    body = re.sub(
        r"\b" + re.escape(template.name) + r"\b",
        target.name,
        read(ROOT, source)[start:end],
    )
    if dry:
        return f"DRY {target_ref} <- {template_ref}\n{body}"
    path = ROOT / target.src
    path.write_text(text.replace(marker, body.strip("\n")), encoding="utf-8")
    exact, detail = match(target_ref)
    if exact:
        return f"EXACT {target_ref} <- {template_ref} in {target.src}"
    path.write_text(text, encoding="utf-8")
    return f"FAIL {target_ref} <- {template_ref}: {detail}"


def main(argv: list[str] | None = None) -> int:
    """Try every row."""
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument("rows", type=Path, help="TSV: TARGET@NAME, TEMPLATE@NAME")
    parser.add_argument(
        "--dry-run", action="store_true", help="print each body; change nothing"
    )
    args = parser.parse_args(argv)
    funcs = load_index(ROOT)
    for row in args.rows.read_text(encoding="utf-8").splitlines():
        if row.strip() and not row.startswith("#"):
            print(attempt(funcs, row, args.dry_run), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
