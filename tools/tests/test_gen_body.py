"""gen_body lifts straight-line assembly, sorts it into shapes and writes typed C."""

from __future__ import annotations

from pathlib import Path

import pytest

import gen_body

CALLS = """\
addiu $sp, $sp, -0x18
sw $ra, 0x10($sp)
addiu $a0, $zero, 0x7
jal Party_JoinMember
addu $a1, $zero, $zero
lui $at, %hi(g_PartySize)
sb $zero, %lo(g_PartySize)($at)
lw $ra, 0x10($sp)
jr $ra
addiu $sp, $sp, 0x18
""".splitlines()

SPAD = """\
lui $v0, (0x1F800044 >> 16)
lw $v0, (0x1F800044 & 0xFFFF)($v0)
nop
lbu $v1, 0x2($v0)
nop
addiu $v1, $v1, 0x1
sb $v1, 0x2($v0)
jr $ra
nop
""".splitlines()


def ctx(members: dict[int, tuple[str, int]] | None = None) -> dict:
    return {"tree": gen_body.Tree(Path(".")), "files": [], "members": members or {}}


def test_a_call_sequence_keeps_constant_arguments_and_global_stores() -> None:
    lifted = gen_body.lift(CALLS)
    assert gen_body.classify(lifted) == "call-seq"
    assert gen_body.statements(lifted, ctx()) == [
        "Party_JoinMember(7, 0);",
        "g_PartySize = 0;",
    ]


def test_a_member_increment_reads_as_postfix_increment() -> None:
    lifted = gen_body.lift(SPAD)
    assert gen_body.classify(lifted) == "spad"
    assert gen_body.statements(lifted, ctx({2: ("unk_02", 1)})) == [
        "g_SpadWork->unk_02++;"
    ]


def test_a_member_without_a_known_offset_is_unsupported() -> None:
    with pytest.raises(gen_body.Unsupported):
        gen_body.statements(gen_body.lift(SPAD), ctx())


def test_a_branch_makes_the_branch_shape() -> None:
    assert gen_body.classify(gen_body.lift(["beqz $v0, .L1", "nop"])) == "branch"


def test_a_jalr_makes_the_dispatch_shape() -> None:
    assert gen_body.classify(gen_body.lift(["jalr $v0", "nop"])) == "dispatch"


def test_a_constant_left_in_v0_is_the_return_value() -> None:
    lifted = gen_body.lift(["jal f", "nop", "addu $v0, $zero, $zero", "jr $ra", "nop"])
    assert lifted.ret == ("c", 0)


def test_struct_members_take_their_offset_from_the_name_or_the_note() -> None:
    body = "u8 flags_00;\nu8 slot; /* +0x05 slot */\ns32 unk_0C;\n"
    assert gen_body.Tree(Path(".")).parse(body, []) == {
        0: ("flags_00", 1),
        5: ("slot", 1),
        12: ("unk_0C", 4),
    }
