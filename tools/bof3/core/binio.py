"""Little-endian integer access for the PS1 binaries."""

from __future__ import annotations


def u32(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 4], "little")
