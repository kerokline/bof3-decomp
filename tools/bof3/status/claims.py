"""What an authored file claims about the unit it is named for.

A `MATCH`/`NON_MATCHING` marker is a claim, not proof; one naming another
address is `foreign` and the claim is withheld. A marker line names its
function by ``func_ADDR`` or by the name it defines (``MATCH void
UI_HandleStartButton(void)``), which ``names`` (the image's symbol rows,
name -> address) resolves; without the row a renamed function is unnamed.
"""

from __future__ import annotations

import re
from collections.abc import Mapping
from dataclasses import dataclass
from functools import cache
from pathlib import Path
from types import MappingProxyType

MATCH = "MATCH"
NON_MATCHING = "NON_MATCHING"

# Horizontal-only leading whitespace: `\s*` can match on a blank line above the
# marker, so `read`'s line slice would begin there and miss the named address.
MARKER_RE = re.compile(rf"^[ \t]*({MATCH}|{NON_MATCHING})\b", re.MULTILINE)
FUNC_RE = re.compile(r"\bfunc_([0-9A-Fa-f]{8})\b")
#: The name a marker line defines: the first identifier followed by `(`.
DEFINED_NAME_RE = re.compile(r"\b([A-Za-z_]\w*)\s*\(")
NO_NAMES: Mapping[str, int] = MappingProxyType({})
INCLUDE_ASM_RE = re.compile(
    r"^[ \t]*(?:#\s*else[ \t]*)?(?:MATCH[ \t]+)?INCLUDE_ASM\s*"
    r"\(\s*(?:[^,()]+,\s*)?func_(?P<address>[0-9A-Fa-f]{8})\s*\)",
    re.MULTILINE,
)

QUOTE_INCLUDE_RE = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"([^"]+)"', re.MULTILINE)


@cache
def _own(path: Path) -> tuple[str, tuple[Path, ...]]:
    """Return one file's text and the quoted includes the compiler finds (`-I` file dir, src, include)."""
    text = path.read_text(encoding="utf-8", errors="replace")
    roots = [path.parent]
    for ancestor in path.parents:
        if ancestor.name == "src":
            roots += [ancestor, ancestor.parent / "include"]
    found = []
    for name in QUOTE_INCLUDE_RE.findall(text):
        hit = next((r / name for r in roots if (r / name).is_file()), None)
        if hit is not None:
            found.append(hit.resolve())
    return text, tuple(found)


def source_text(path: Path) -> str:
    """Return the file's text followed by the text of every header it includes, once each.

    A shared-body member holds only ``#include "family/Name.h"``; the marker and the
    definition live in that header.
    """
    seen: set[Path] = set()
    pending = [path.resolve()]
    parts = []
    while pending:
        current = pending.pop(0)
        if current in seen:
            continue
        seen.add(current)
        text, includes = _own(current)
        parts.append(text)
        pending.extend(includes)
    return "\n".join(parts)


KIND_OF_CLAIM = {MATCH: "matching", NON_MATCHING: "non_matching"}


@dataclass(frozen=True, slots=True)
class Marker:
    """One source marker, resolved against the requested function address."""

    kind: str | None
    foreign: int | None
    claim: str | None
    path: Path


def read(path: Path, unit_address: int, names: Mapping[str, int] = NO_NAMES) -> Marker:
    """Read the marker for `unit_address`, preserving single-marker files."""
    text = source_text(path)
    found = []
    for match in MARKER_RE.finditer(text):
        end = text.find("\n", match.start())
        line = text[match.start() : end if end >= 0 else len(text)]
        found.append((match.group(1), _named_address(line, names)))
    if not found:
        return Marker(kind=None, foreign=None, claim=None, path=path)
    for claim, named in found:
        if named == unit_address:
            return Marker(
                kind=KIND_OF_CLAIM[claim], foreign=None, claim=claim, path=path
            )
    if len(found) == 1 and found[0][1] is None:
        claim, _ = found[0]
        return Marker(kind=KIND_OF_CLAIM[claim], foreign=None, claim=claim, path=path)
    claim, foreign = found[0]
    return Marker(kind=None, foreign=foreign, claim=claim, path=path)


def _named_address(line: str, names: Mapping[str, int] = NO_NAMES) -> int | None:
    match = FUNC_RE.search(line)
    if match:
        return int(match.group(1), 16)
    defined = DEFINED_NAME_RE.search(line)
    return names.get(defined.group(1)) if defined else None


def function_claims(
    text: str, names: Mapping[str, int] = NO_NAMES
) -> dict[int, str | None]:
    """Map marked definitions and assembly includes to their function addresses."""
    found = {}
    for marker in MARKER_RE.finditer(text):
        end = text.find("\n", marker.start())
        line = text[marker.start() : end if end >= 0 else len(text)]
        address = _named_address(line, names)
        if address is not None:
            found.setdefault(address, KIND_OF_CLAIM[marker.group(1)])
    for include in INCLUDE_ASM_RE.finditer(text):
        address = int(include["address"], 16)
        found.setdefault(address, None)
    return found


DEFINITION_RE = re.compile(
    r"^[A-Za-z_][^;{}()=\n]*\bfunc_(?P<address>[0-9A-Fa-f]{8})\s*\([^;{}]*\)\s*\{",
    re.MULTILINE,
)


def function_addresses(text: str, names: Mapping[str, int] = NO_NAMES) -> set[int]:
    """Addresses of every function a file defines, claims, or includes as assembly."""
    found = set(function_claims(text, names))
    found.update(int(m["address"], 16) for m in DEFINITION_RE.finditer(text))
    return found
