#include "plp056_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801CE404(void) {
    D_801D0858[((u8*)g_SpadWork)[2]]();
}

INCLUDE_ASM(func_801CE448);

INCLUDE_ASM(func_801CE628);

MATCH void func_801CE72C(void) {
    SYS_DISPATCH_TASK(D_801D0864, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CE770);

INCLUDE_ASM(func_801CEA94);

#include "overlays/plchar/Char_AdvanceScript.h"

INCLUDE_ASM(func_801CED1C);

#include "overlays/plchar/Char_SpawnActor.h"

#include "overlays/plchar/Char_ProbeFacingCell.h"

MATCH void func_801CF12C(void) {
    SYS_DISPATCH_TASK(D_801D0870, 2, g_SpadWork);
}

#include "overlays/plchar/Char_StartTurn.h"

/* Follows CHAR_RUN_STEP_SCRIPT (plchar.h), but retail branches on the second
 * facing with `bne` and the 0x41 load in the delay slot, where the macro emits
 * `beq`; the script selection needs another switch or if form. */
INCLUDE_ASM(func_801CF23C);

MATCH void func_801CF338(void) {
    SYS_DISPATCH_TASK(D_801D087C, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CF37C);

INCLUDE_ASM(func_801CF548);

INCLUDE_ASM(func_801CF654);

MATCH void func_801CF728(void) {
    SYS_DISPATCH_TASK(D_801D0888, 2, g_SpadWork);
}

MATCH void Char_StartTurn_801CF76C(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

#include "overlays/plchar/Char_RunStepScript.h"

MATCH void func_801CF934(void) {
    func_8014D978();
}

MATCH void func_801CF954(void) {
    SYS_DISPATCH_TASK(D_801D0894, 2, g_SpadWork);
}

MATCH void func_801CF998(void) {
    SYS_DISPATCH_TASK(D_801D089C, 3, g_SpadWork);
}

INCLUDE_ASM(func_801CF9DC);

INCLUDE_ASM(func_801CFADC);

INCLUDE_ASM(func_801CFD28);

INCLUDE_ASM(func_801CFE58);

INCLUDE_ASM(func_801CFEB8);

INCLUDE_ASM(func_801CFF4C);

INCLUDE_ASM(func_801D0158);

MATCH void func_801D0244(void) {
    SYS_DISPATCH_TASK(D_801D08B0, 3, g_SpadWork);
}

INCLUDE_ASM(func_801D0288);

INCLUDE_ASM(func_801D02F4);

INCLUDE_ASM(func_801D042C);

INCLUDE_ASM(func_801D04C8);

INCLUDE_ASM(func_801D066C);

MATCH void func_801D07D0(void) {
    D_801D08BC[g_SpadWork->unk_2C]();
}

MATCH void func_801D0814(void) {
    D_801D08C8[g_SpadWork->unk_2C]();
}
