"""A symbol row as tools read it.

``bof3.link.symbols`` reads ``config/symbols.toml`` and hands each row to its callers as a
:class:`Row`: the name, the address, and a comment that carries the attributes
(``type:func size:0x3C``, ``alias:true``, ``source="..."``). Splat and the link read the files
generated from the same table.
"""

from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class Row:
    """One map row: the name, its address, and the trailing comment as written."""

    name: str
    address: int
    comment: str = ""

    @property
    def alias(self) -> bool:
        """True for a name only the link reads: Splat never sees an ``alias:true`` row."""
        return "alias:true" in self.comment.split()
