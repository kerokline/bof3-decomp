"""Read a linker script's input lines and write generated text; loads fast for short-lived tools."""

from __future__ import annotations

import re
from pathlib import Path
from typing import NamedTuple

__all__ = ["Input", "parse", "write_if_changed"]


class Input(NamedTuple):
    """One ``path(section);`` line of a linker script."""

    line: int
    path: str
    section: str


_INPUT = re.compile(r"^(\s*)([^\s()]+)\(([^()]+)\);\s*$")


def parse(text: str) -> tuple[Input, ...]:
    """Return input selectors in file order, excluding directives and discards."""
    inputs: list[Input] = []
    for number, line in enumerate(text.splitlines(), 1):
        match = _INPUT.match(line)
        if match is None:
            continue
        path, section = match[2], match[3]
        if path == "*" or not section.startswith("."):
            continue
        inputs.append(Input(number, path, section))
    return tuple(inputs)


def write_if_changed(path: Path, text: str) -> None:
    """Write generated text only when its bytes differ."""
    data = text.encode("utf-8")
    if path.is_file() and path.read_bytes() == data:
        return
    from bof3.core.io import write_atomic

    write_atomic(path, data)
