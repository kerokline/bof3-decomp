from __future__ import annotations

import pytest

from bof3.source import symtab


def table(*rows: str) -> str:
    return "\n".join(['["exe/a"]', *rows, "", '["exe/c"]', "Z = { addr = 0x1 }", ""])


def test_a_row_lands_in_address_order() -> None:
    text = table("A = { addr = 0x10 }", "C = { addr = 0x30 }")
    row = symtab.format_row("B", 0x20, type="func", size=8, source="seen at x")
    assert (
        row
        == 'B = { addr = 0x00000020, type = "func", size = 0x8, source = "seen at x" }'
    )
    out = symtab.add_row(text, "exe/a", "B", row, 0x20).split("\n")
    assert [line[:1] for line in out[1:4]] == ["A", "B", "C"]
    assert out[-3:] == ['["exe/c"]', "Z = { addr = 0x1 }", ""]


def test_a_new_image_starts_its_own_table_in_order() -> None:
    out = symtab.add_row(
        table("A = { addr = 0x10 }"), "exe/b", "N", "N = { addr = 0x5 }", 5
    )
    assert out.index('["exe/a"]') < out.index('["exe/b"]') < out.index('["exe/c"]')


def test_a_rename_keeps_the_row_and_refuses_a_taken_name() -> None:
    text = table("A = { addr = 0x10 }", "B = { addr = 0x20 }")
    assert "Alpha = { addr = 0x10 }" in symtab.rename_row(text, "exe/a", "A", "Alpha")  # type: ignore[operator]
    assert symtab.rename_row(text, "exe/a", "Q", "R") is None
    with pytest.raises(symtab.SymtabError):
        symtab.rename_row(text, "exe/a", "A", "B")
