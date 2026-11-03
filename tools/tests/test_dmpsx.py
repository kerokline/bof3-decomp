from __future__ import annotations

from psxdecomp.dmpsx import rewrite_text


def test_a_placeholder_in_text_is_rewritten():
    updated, count = rewrite_text(".text\n\t.word\t0x7F\n")

    assert count == 1
    assert updated == ".text\n\t.word\t0x4A180001\n"


def test_a_data_word_that_looks_like_a_placeholder_is_left_alone():
    text = ".data\n\t.word\t0x7F\n.section .rodata\n\t.word\t0x3F\n"

    updated, count = rewrite_text(text)

    assert count == 0
    assert updated == text
