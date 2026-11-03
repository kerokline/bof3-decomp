#include "plp026_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801CE404(void) {
    D_801D0A54[((u8*)g_SpadWork)[2]]();
}

INCLUDE_ASM(func_801CE448);

INCLUDE_ASM(func_801CE628);

MATCH void func_801CE72C(void) {
    SYS_DISPATCH_TASK(D_801D0A60, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CE770);

INCLUDE_ASM(func_801CEA94);

#include "overlays/plchar/Char_AdvanceScript.h"

INCLUDE_ASM(func_801CED1C);

#include "overlays/plchar/Char_SpawnActor.h"

#include "overlays/plchar/Char_ProbeFacingCell.h"

MATCH void func_801CF12C(void) {
    SYS_DISPATCH_TASK(D_801D0A6C, 2, g_SpadWork);
}

#include "overlays/plchar/Char_StartTurn.h"

MATCH void Char_RunStepScript_801CF23C(void) {
    CHAR_RUN_STEP_SCRIPT(CHARACTER_FACING_AWAY, CHARACTER_FACING_BACK);
}

MATCH void func_801CF338(void) {
    SYS_DISPATCH_TASK(D_801D0A78, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CF37C);

INCLUDE_ASM(func_801CF564);

INCLUDE_ASM(func_801CF5D4);

INCLUDE_ASM(func_801CF738);

INCLUDE_ASM(func_801CF808);

MATCH void func_801CF924(void) {
    SYS_DISPATCH_TASK(D_801D0A80, 2, g_SpadWork);
}

MATCH void Char_StartTurn_801CF968(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

#include "overlays/plchar/Char_RunStepScript.h"

MATCH void func_801CFB30(void) {
    func_8014D978();
}

MATCH void func_801CFB50(void) {
    SYS_DISPATCH_TASK(D_801D0A8C, 2, g_SpadWork);
}

MATCH void func_801CFB94(void) {
    SYS_DISPATCH_TASK(D_801D0A94, 3, g_SpadWork);
}

INCLUDE_ASM(func_801CFBD8);

INCLUDE_ASM(func_801CFCD8);

INCLUDE_ASM(func_801CFF24);

INCLUDE_ASM(func_801D0054);

INCLUDE_ASM(func_801D00B4);

INCLUDE_ASM(func_801D0148);

INCLUDE_ASM(func_801D0354);

MATCH void func_801D0440(void) {
    SYS_DISPATCH_TASK(D_801D0AA8, 3, g_SpadWork);
}

INCLUDE_ASM(func_801D0484);

INCLUDE_ASM(func_801D04F0);

INCLUDE_ASM(func_801D0628);

INCLUDE_ASM(func_801D06C4);

INCLUDE_ASM(func_801D0868);

MATCH void func_801D09CC(void) {
    D_801D0AB4[g_SpadWork->unk_2C]();
}

MATCH void func_801D0A10(void) {
    D_801D0AC0[g_SpadWork->unk_2C]();
}
