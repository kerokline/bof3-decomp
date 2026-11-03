"""The Rizin project reads linker maps, trims headers to types and keeps one flag per name."""

from __future__ import annotations

from pathlib import Path

import rzproject
from rzproject import MapSymbol

MAP = """\
 .text          0x80010000       0x20 src+a.c.o
                0x80010000                func_80010000
                0x80010010                func_80010010
 .data          0x80020000        0x8 src+a.c.o
                0x80020000                D_80020000
                0x90000000                outside
                0x80030000                D_80030000 = 0x80030000
"""


def test_a_map_symbol_runs_to_the_next_one_or_the_section_end(tmp_path: Path) -> None:
    path = tmp_path / "image.map"
    path.write_text(MAP, encoding="utf-8")
    assert rzproject.read_map(path) == [
        MapSymbol("func_80010000", 0x80010000, 0x10, True),
        MapSymbol("func_80010010", 0x80010010, 0x10, True),
        MapSymbol("D_80030000", 0x80030000, 0, False),
        MapSymbol("D_80020000", 0x80020000, 8, False),
    ]


def test_types_keep_declarations_and_drop_callables_and_repeats() -> None:
    text = "\n".join(
        [
            "int Run(int x);",
            "typedef struct Pair {",
            "    int a;",
            "    void (*cb)(int);",
            "    int bit : 3;",
            "} Pair;",
            "typedef unsigned char u8;",
            "typedef unsigned char u8;",
        ]
    )
    out = rzproject.types_only(text)
    assert "Run" not in out
    assert out.count("typedef unsigned char u8;") == 1
    assert "struct Pair {" in out
    assert "} Pair;" not in out
    assert "void *cb;" in out
    assert ":" not in out


def test_one_flag_per_name_and_a_shared_name_takes_its_address() -> None:
    lines = [
        "f Foo 4 @ 0x80010000",
        "f Foo 4 @ 0x80010000",
        "f Foo 4 @ 0x80020000",
        "fs bof3",
    ]
    assert rzproject.unique_flags(lines) == [
        "f Foo 4 @ 0x80010000",
        "f Foo_80020000 4 @ 0x80020000",
        "fs bof3",
    ]


def test_a_second_map_name_at_one_address_goes_to_the_alias_space() -> None:
    mapped = [
        MapSymbol("A", 0x80010000, 8, True),
        MapSymbol("B", 0x80010000, 0, False),
        MapSymbol("A", 0x80010008, 8, True),
    ]
    assert rzproject.map_flags(mapped) == [
        "fs bof3_map",
        "f A 8 @ 0x80010000",
        "fs bof3_alias",
        "f B 1 @ 0x80010000",
    ]
