"""dups groups functions by opcode sequence, shared name and byte-equal body."""

from __future__ import annotations

import argparse

import pytest

import dups
from bof3.source.index import Func

ADDIU = 0x24000001
JR = 0x03E00008


def func(
    name: str,
    words: tuple[int, ...],
    *,
    status: str = "C",
    sha1: str = "",
    image: str = "exe/a",
    addr: int = 0x1000,
) -> Func:
    return Func(
        image, name, addr, 4 * len(words), words, sha1 or name, status, "src/a.c"
    )


def args(**kw: object) -> argparse.Namespace:
    return argparse.Namespace(**{"rebuild": False, "out": None, **kw})


def serve(monkeypatch: pytest.MonkeyPatch, funcs: list[Func]) -> None:
    monkeypatch.setattr(dups, "load_index", lambda root, rebuild: funcs)


def test_functions_drop_sdk_code_and_short_bodies(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    serve(
        monkeypatch,
        [
            func("a", (ADDIU, JR)),
            func("lib", (ADDIU, JR), status="LIB"),
            func("tiny", (JR,)),
        ],
    )
    assert [f.name for f in dups.functions(args(), min_words=2)] == ["a"]


def test_emit_writes_a_tab_separated_table(capsys: pytest.CaptureFixture[str]) -> None:
    dups.emit(args(), ["x", "y"], [[1, "a"], [2, "b"]])
    assert capsys.readouterr().out == "x\ty\n1\ta\n2\tb\n"


def test_emit_writes_the_out_file(tmp_path) -> None:
    out = tmp_path / "t.tsv"
    dups.emit(args(out=str(out)), ["x"], [[1]])
    assert out.read_text(encoding="utf-8") == "x\n1\n"


def test_near_row_pairs_an_assembly_function_with_its_template() -> None:
    lifted = func("lifted", (ADDIU, JR), sha1="h1")
    asm = func("func_1", (ADDIU, JR), status="ASM", sha1="h2", addr=0x2000)
    seq = dups.opcode_string(lifted.words)
    row = dups.near_row({seq: [lifted, asm]}, [seq], [{}], 0, [0])
    assert row is not None
    assert row["kind"] == "opcode-equal"
    assert (row["matched"], row["assembly"], row["candidate"]) == (1, 1, 1)
    assert row["asm_with_template"] == 1
    assert row["templates_top4"] == "exe/a:func_1<-exe/a:lifted@1.000"


def test_near_row_skips_identical_bodies_of_one_kind() -> None:
    a, b = func("a", (ADDIU, JR), sha1="same"), func("b", (ADDIU, JR), sha1="same")
    seq = dups.opcode_string(a.words)
    assert dups.near_row({seq: [a, b]}, [seq], [{}], 0, [0]) is None
    assert dups.near_row({seq: [a]}, [seq], [{}], 0, [0]) is None


def test_near_row_lists_at_most_25_members() -> None:
    members = [
        func(f"f{i}", (ADDIU, JR), sha1=f"h{i}", addr=0x1000 + 8 * i) for i in range(27)
    ]
    seq = dups.opcode_string(members[0].words)
    row = dups.near_row({seq: members}, [seq], [{}], 0, [0])
    assert row is not None
    assert row["member_list"].endswith(" | +2 more")
    assert row["byte_classes"] == 27


def test_split_names_reports_one_body_with_two_real_names(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    words = (ADDIU,) * 6
    serve(
        monkeypatch,
        [
            func("Alpha", words, sha1="s", addr=0x10),
            func("Beta", words, sha1="s", addr=0x20),
            func("Solo", words, sha1="t", addr=0x30),
            func("func_x", words, sha1="u", addr=0x40),
        ],
    )
    assert dups.split_names(args()) == 0
    captured = capsys.readouterr()
    rows = captured.out.splitlines()[1:]
    assert len(rows) == 1
    assert rows[0].split("\t")[:3] == ["2", "0", "2"]
    assert "Alpha Beta" in rows[0]
    assert "1 bodies with several real names" in captured.err


def test_split_names_counts_a_name_with_placeholder_copies(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    words = (ADDIU,) * 6
    serve(
        monkeypatch,
        [func("Alpha", words, sha1="s"), func("func_2", words, sha1="s", addr=0x20)],
    )
    dups.split_names(args())
    assert (
        "0 bodies with several real names; 1 with one name" in capsys.readouterr().err
    )


def test_shared_names_ignores_placeholders_and_unique_names(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    pytest.importorskip("rapidfuzz")
    serve(
        monkeypatch,
        [
            func("Dup", (ADDIU, JR), sha1="a", image="exe/a"),
            func("Dup", (ADDIU, JR), sha1="b", image="exe/b"),
            func("Once", (ADDIU, JR)),
            func("func_1", (ADDIU, JR)),
            func("func_1", (ADDIU, JR), image="exe/b"),
        ],
    )
    assert dups.shared_names(args()) == 0
    rows = capsys.readouterr().out.splitlines()[1:]
    assert len(rows) == 1
    fields = rows[0].split("\t")
    assert fields[:6] == ["1.0", "Dup", "2", "2", "2", "1"]


def test_near_groups_alike_sequences(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    pytest.importorskip("rapidfuzz")
    body = (ADDIU,) * 5 + (JR,)
    serve(
        monkeypatch,
        [
            func("lifted", body, sha1="h1"),
            func("func_1", body, status="ASM", sha1="h2", addr=0x2000),
        ],
    )
    assert dups.near(args(threshold=0.9, min_words=6)) == 0
    captured = capsys.readouterr()
    assert len(captured.out.splitlines()) == 2
    assert "groups 1, with a matched and an assembly member 1" in captured.err
