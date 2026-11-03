#!/usr/bin/env python3
"""Split a Psy-Q ``.LIB`` archive into its LNK object members.

    tools/psyq_lib.py LIB OUTDIR

Writes ``OUTDIR/<member>.obj`` (lower case). A name repeated in the archive gets
``_2``, ``_3`` ... in order. No other tool reads this archive format.
"""

import struct
import sys
from collections.abc import Iterator
from pathlib import Path


def members(data: bytes) -> Iterator[tuple[str, bytes]]:
    """Yield (name, LNK bytes) for each member of a Psy-Q LIB archive."""
    if data[:4] != b"LIB\x01":
        raise SystemExit("psyq_lib: not a Psy-Q LIB archive")
    pos = 4
    while pos + 20 <= len(data) and data[pos] != 0:
        name = data[pos : pos + 8].decode("ascii", "replace").strip()
        _, offset, size = struct.unpack_from("<III", data, pos + 8)
        yield name, data[pos + offset : pos + size]
        pos += size


def main() -> None:
    """Write each member of LIB to OUTDIR."""
    lib, outdir = Path(sys.argv[1]), Path(sys.argv[2])
    outdir.mkdir(parents=True, exist_ok=True)
    seen: dict[str, int] = {}
    for name, lnk in members(lib.read_bytes()):
        count = seen[name] = seen.get(name, 0) + 1
        stem = name.lower() + ("" if count == 1 else f"_{count}")
        (outdir / f"{stem}.obj").write_bytes(lnk)


if __name__ == "__main__":
    main()
