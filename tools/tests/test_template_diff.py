"""template_diff prints only the instructions that differ, aligned on opcodes."""

from __future__ import annotations

from types import SimpleNamespace

import pytest

import template_diff


def listing(
    monkeypatch: pytest.MonkeyPatch, template: list[str], target: list[str]
) -> None:
    by_words = {(1,): template, (2,): target}
    monkeypatch.setattr(template_diff, "disassemble", lambda words: by_words[words])


def test_same_opcode_with_other_operands_is_marked_changed(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    listing(monkeypatch, ["addiu v0,zero,1", "jr ra"], ["addiu v0,zero,2", "jr ra"])
    shown = template_diff.show(SimpleNamespace(words=(1,)), SimpleNamespace(words=(2,)))
    out = capsys.readouterr().out
    assert shown == 1
    assert out.startswith("~ +0x000 addiu v0,zero,1")
    assert "| +0x000 addiu v0,zero,2" in out
    assert "jr" not in out.splitlines()[0]


def test_extra_instructions_are_marked_on_their_side(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    listing(monkeypatch, ["nop", "jr ra"], ["nop", "lw v0,0(a0)", "jr ra"])
    shown = template_diff.show(SimpleNamespace(words=(1,)), SimpleNamespace(words=(2,)))
    lines = capsys.readouterr().out.splitlines()
    assert shown == 1
    assert lines[0] == "+ +0x004 lw v0,0(a0)"
    assert lines[-1] == "1 differing of 2 template and 3 target instructions"
