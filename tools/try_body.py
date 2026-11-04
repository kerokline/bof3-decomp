#!/usr/bin/env python3
"""Put a C body in place of one INCLUDE_ASM function, test it, and keep it only if it matches.

    tools/try_body.py TARGET@NAME [BODY.c | -]      one body from a file or stdin
    tools/try_body.py --batch ROWS.tsv              rows of TARGET@NAME, a tab, BODY.c

TARGET@NAME is the image and the function (`exe/slus_004_22@Actor_FindFree` or
`TARGET@0xADDRESS`). The body replaces the `INCLUDE_ASM(NAME);` line of the function's C file. A
line `@decl <declaration>` in the body file is removed from the body and added to the image's
declaration header (the file the C file includes first) unless a header of the include chain
already declares that name. The tool then runs `tools/match.sh`. A `match` keeps every edit; any
other result restores every touched file. One line per body: `EXACT`, `FAIL` with the first
difference, or `SKIP` with the reason. A kept body is a lead: run `meson compile -C
build/meson check-<image>`, then name and share it (docs/conventions.md).
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

from bof3.source.ctext import read
from bof3.source.index import Func, find, load_index
from bof3.source.remap import declaration

ROOT = Path(__file__).resolve().parent.parent
QUOTED = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)
DECL = re.compile(r"^@decl\s+(.*)$", re.M)


def resolve(root: Path, src: str, include: str, anywhere: bool = False) -> str | None:
    """Return the repo path of a quoted include of ``src`` under ``src/`` (or ``include/``)."""
    for base in (str(Path(src).parent), "src/shared", "src", "include"):
        candidate = (Path(base) / include).as_posix()
        if (root / candidate).is_file() and (anywhere or candidate.startswith("src/")):
            return candidate
    return None


def closure(root: Path, src: str, depth: int = 3, anywhere: bool = False) -> list[str]:
    """Return ``src`` and the headers it includes, as repo paths, nearest first.

    ``anywhere`` follows includes into ``include/`` too.
    """
    seen: list[str] = []

    def walk(path: str, left: int) -> None:
        if path in seen:
            return
        seen.append(path)
        if left:
            for inc in QUOTED.findall(read(root, path)):
                found = resolve(root, path, inc, anywhere)
                if found:
                    walk(found, left - 1)

    walk(src, depth)
    return seen


def declares(root: Path, src: str, name: str) -> bool:
    """Say whether ``src`` or a header it includes declares or defines ``name``."""
    define = re.compile(r"^[ \t]*#[ \t]*define[ \t]+" + re.escape(name) + r"\b", re.M)
    return any(
        define.search(read(root, f))
        or declaration(read(root, f), name)
        or re.search(r"\b" + re.escape(name) + r"\s*\([^;{]*\)\s*\{", read(root, f))
        for f in closure(root, src, 6, True)
    )


def image_header(root: Path, src: str) -> str | None:
    """Return the first quoted include of ``src``: the image's declaration header."""
    for inc in QUOTED.findall(read(root, src)):
        return resolve(root, src, inc)
    return None


def split_decls(text: str) -> tuple[str, list[str]]:
    """Return the body without its ``@decl`` lines, and those declarations."""
    return DECL.sub("", text).strip("\n"), [d.strip() for d in DECL.findall(text)]


def declared_name(decl: str) -> str | None:
    """Return the name a one-line declaration introduces."""
    if decl.startswith("#define"):
        return decl.split()[1]
    m = re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*(?:\([^;]*\))?\s*;?\s*$", decl)
    return m.group(1) if m else None


def add_declarations(header: str, decls: list[str]) -> str:
    """Return ``header`` with the declarations added: externs after the last one, the rest last."""
    for decl in decls:
        if decl.startswith("#define"):
            lines = header.split("\n")
            last = max(
                (i for i, ln in enumerate(lines) if ln.startswith("#include")),
                default=-1,
            )
            lines.insert(last + 1, decl)
            header = "\n".join(lines)
            continue
        decl = decl.rstrip(";") + ";"
        is_extern = decl.startswith("extern ") and "(" not in decl
        lines = header.split("\n")
        last = max(
            (
                i
                for i, ln in enumerate(lines)
                if ln.startswith("extern ") and ln.endswith(";") and "(" not in ln
            ),
            default=-1,
        )
        if is_extern and last >= 0:
            lines.insert(last + 1, decl)
            header = "\n".join(lines)
            continue
        end = header.rfind("#endif")
        if end < 0:
            header = header.rstrip("\n") + f"\n\n{decl}\n"
        else:
            header = header[:end].rstrip("\n") + f"\n\n{decl}\n\n" + header[end:]
    return header


def match(ref: str, root: Path = ROOT) -> tuple[bool, str]:
    """Run ``tools/match.sh`` on one function; return (exact, last lines)."""
    target, _, name = ref.partition("@")
    result = subprocess.run(
        ["sh", "tools/match.sh", target, name],
        cwd=root,
        capture_output=True,
        text=True,
        check=False,
    )
    tail = (result.stdout + result.stderr).strip().splitlines()[-3:]
    return result.returncode == 0, " | ".join(x.strip() for x in tail)[:230]


def attempt(root: Path, func: Func, text: str) -> tuple[str, str]:
    """Try the body ``text`` for ``func``; return (status, detail)."""
    body, decls = split_decls(text)
    if func.status != "ASM" or not func.src:
        return "SKIP", "not an INCLUDE_ASM function"
    marker = f"INCLUDE_ASM({func.name});"
    path = root / func.src
    original = read(root, func.src)
    if marker not in original:
        return "SKIP", "already has a body"
    touched = {path: original}
    header = image_header(root, func.src)
    missing = [d for d in decls if not declares(root, func.src, declared_name(d) or "")]
    try:
        if missing and header:
            hpath = root / header
            touched[hpath] = read(root, header)
            hpath.write_text(
                add_declarations(touched[hpath], missing), encoding="utf-8"
            )
        path.write_text(original.replace(marker, body), encoding="utf-8")
        exact, detail = match(f"{func.image}@{func.name}", root)
    except BaseException:
        restore(touched)
        raise
    if exact:
        return "EXACT", func.src
    restore(touched)
    return "FAIL", detail


def restore(touched: dict[Path, str]) -> None:
    """Write every touched file back as it was."""
    for path, text in touched.items():
        path.write_text(text, encoding="utf-8")


def run_one(funcs: list[Func], ref: str, source: Path | None) -> str:
    """Try one body and return its report line."""
    text = sys.stdin.read() if source is None else source.read_text(encoding="utf-8")
    status, detail = attempt(ROOT, find(funcs, ref), text)
    return f"{status} {ref}" + (f": {detail}" if detail else "")


def main(argv: list[str] | None = None) -> int:
    """Try one body or a batch."""
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument("target", nargs="?", help="TARGET@NAME or TARGET@0xADDRESS")
    parser.add_argument("body", nargs="?", help="body file; - or omitted reads stdin")
    parser.add_argument("--batch", type=Path, help="TSV of TARGET@NAME, BODY.c")
    args = parser.parse_args(argv)
    funcs = load_index(ROOT)
    if args.batch:
        for row in args.batch.read_text(encoding="utf-8").splitlines():
            if row.strip() and not row.startswith("#"):
                ref, body = row.split("\t")[:2]
                print(run_one(funcs, ref, Path(body)), flush=True)
        return 0
    if not args.target:
        parser.error("give TARGET@NAME or --batch ROWS.tsv")
    source = None if args.body in (None, "-") else Path(args.body)
    line = run_one(funcs, args.target, source)
    print(line)
    return 0 if line.startswith("EXACT") else 1


if __name__ == "__main__":
    raise SystemExit(main())
