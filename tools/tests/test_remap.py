"""remap lines up a template with a target and turns the differences into C edits."""

from __future__ import annotations

from bof3.source import remap
from bof3.source.remap import Insn

LUI = 0x3C020000
LW = 0x8C420000
JAL = 0x0C000000
ADDIU = 0x24420000


def test_diff_count_ignores_jump_targets() -> None:
    assert remap.diff_count((JAL | 5, ADDIU | 1), (JAL | 9, ADDIU | 1)) == 0
    assert remap.diff_count((ADDIU | 1, ADDIU | 2), (ADDIU | 1, ADDIU | 3)) == 1
    assert remap.diff_count((ADDIU, ADDIU, ADDIU), (ADDIU,)) == 2


OBJDUMP = """
00000000 <other>:
   0:\t27bdffe8 \taddiu\tsp,sp,-24
00000004 <Fn>:
   4:\t3c020000 \tlui\tv0,0x0
\t\t\t4: R_MIPS_HI16\tD_8001
   8:\t8c420008 \tlw\tv0,8(v0)
\t\t\t8: R_MIPS_LO16\tD_8001
   c:\t0c000000 \tjal\t0 <Fn>
\t\t\tc: R_MIPS_26\t.text
"""


def test_template_insns_picks_one_function_and_its_relocations() -> None:
    got = remap.template_insns(OBJDUMP, "Fn", 3)
    assert got == [
        Insn(0x3C020000, "D_8001"),
        Insn(0x8C420008, "D_8001", 8),
        Insn(0x0C000000, ""),
    ]
    assert remap.template_insns(OBJDUMP, "Fn", 4) == []
    assert remap.template_insns(OBJDUMP, "Missing", 1) == []


def test_target_insns_reads_symbols_addends_and_local_jumps() -> None:
    got = remap.target_insns(
        (1, 2, 3, 4, 5),
        [
            "lui        $v0, %hi(D_8002)",
            "lw         $v0, %lo(D_8002 + 0x8)($v0)",
            "jal        func_9000",
            "j          .L8001",
            "nop",
        ],
    )
    assert [(i.sym, i.addend) for i in got] == [
        ("D_8002", 0),
        ("D_8002", 8),
        ("func_9000", 0),
        ("", 0),
        (None, 0),
    ]


def test_align_names_a_symbol_that_differs() -> None:
    t = [Insn(LUI, "D_1"), Insn(LW | 8, "D_1", 8), Insn(JAL, "f_1")]
    g = [Insn(LUI | 1, "D_2"), Insn(LW | 8, "D_2", 8), Insn(JAL | 4, "f_2")]
    plan = remap.align(t, g, (LUI, LW | 8, JAL))
    assert plan is not None and plan.hard == 0
    assert plan.symbols == {"D_1": "D_2", "f_1": "f_2"}
    assert plan.total == 3


def test_align_rejects_two_targets_for_one_symbol_and_other_operands() -> None:
    t = [Insn(LUI, "D_1"), Insn(LUI, "D_1")]
    plan = remap.align(t, [Insn(LUI, "D_2"), Insn(LUI, "D_3")], (LUI, LUI))
    assert plan is not None and plan.hard == 1 and "two symbols" in plan.first_hard
    plan = remap.align([Insn(LUI, "D_1")], [Insn(LUI | 0x10000, "D_2")], (LUI,))
    assert plan is not None and plan.hard == 1


def test_align_collects_literals_and_unexplained_words() -> None:
    t = [Insn(ADDIU | 5), Insn(LUI | 0x10000), Insn(0x03E00008)]
    g = [Insn(ADDIU | 7), Insn(LUI), Insn(0x03E00008)]
    plan = remap.align(t, g, tuple(i.word for i in t))
    assert plan is not None and plan.literals == [(5, 7)] and plan.hard == 1


def test_align_keeps_a_symbol_the_target_writes_as_an_address() -> None:
    t = [Insn(LUI | 0x1F80, "g_Spad")]
    g = [Insn(LUI | 0x1F80)]
    plan = remap.align(t, g, (LUI | 0x1F80,))
    assert plan is not None and plan.keep == {"g_Spad"} and not plan.edits
    assert remap.align(t, g + g, (LUI,)) is None


def test_rename_matches_whole_identifiers_only() -> None:
    assert remap.rename("a = D_1 + D_10;", "D_1", "D_2") == "a = D_2 + D_10;"
    assert remap.rename("a = 1;", "D_1", "D_2") is None


def test_substitute_literals_needs_each_literal_once() -> None:
    assert remap.substitute_literals("x = y + 5;", [(5, 7)]) == "x = y + 7;"
    assert remap.substitute_literals("x = y - 5;", [(0xFFFB, 0xFFF9)]) == "x = y - 7;"
    assert remap.substitute_literals("m = 0x10;", [(0x10, 0x20)]) == "m = 0x20;"
    assert remap.substitute_literals("x = 5 + 5;", [(5, 7)]) is None
    assert remap.substitute_literals("x = 1;", [(5, 7)]) is None
    assert remap.substitute_literals("x = 5 + 5;", [(5, 7), (5, 7)]) == "x = 7 + 7;"
    assert remap.substitute_literals("x = 5;", [(5, 7), (5, 8)]) is None
    assert remap.substitute_literals('s = "5"; x = 5;', [(5, 7)]) == 's = "5"; x = 7;'


HEADER = """#define STRIDE 0x28 /* row */
#define EXPR (1 + 2)
extern s16 D_1[];
extern s8 a, b;
void Fn(int x);
int Def(void) { return 1; }
static int hidden;
typedef struct { int m; } S;
extern S g_S;
"""


def test_declaration_finds_one_line_externs_and_prototypes() -> None:
    assert remap.declaration(HEADER, "D_1") == "extern s16 D_1[];"
    assert remap.declaration(HEADER, "Fn") == "void Fn(int x);"
    assert remap.declaration(HEADER, "g_S") == "extern S g_S;"
    assert remap.declaration(HEADER, "a") is None
    assert remap.declaration(HEADER, "Def") is None
    assert remap.declaration(HEADER, "hidden") is None


def test_macro_edits_define_a_numeric_macro_for_the_target() -> None:
    left, out = remap.macro_edits("p += STRIDE;", [(0x28, 0x1C)], [HEADER])
    assert left == [] and out == ["#define STRIDE 0x1C"]
    left, out = remap.macro_edits("p += STRIDE + STRIDE;", [(0x28, 0x1C)], [HEADER])
    assert left == [(0x28, 0x1C)] and out == []


def test_used_defines_lists_the_numeric_macros_a_body_uses() -> None:
    assert remap.used_defines("p += STRIDE; q = EXPR;", [HEADER]) == [
        "#define STRIDE 0x28"
    ]
