#include "plp257_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801CE404(void) {
    D_801CFEDC[((u8*)g_SpadWork)[2]]();
}

MATCH void Char_StartTurn_801CE448(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

MATCH void Char_RunStepScript_801CE514(void) {
    CHAR_RUN_STEP_SCRIPT(CHARACTER_FACING_AWAY, CHARACTER_FACING_BACK);
}

MATCH void func_801CE610(void) {
    SYS_DISPATCH_TASK(D_801CFEE8, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CE654);

INCLUDE_ASM(func_801CE83C);

INCLUDE_ASM(func_801CE8AC);

INCLUDE_ASM(func_801CEA10);

INCLUDE_ASM(func_801CEAE0);

MATCH void func_801CEBFC(void) {
    SYS_DISPATCH_TASK(D_801CFEF0, 2, g_SpadWork);
}

MATCH void Char_StartTurn(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

/* Follows CHAR_RUN_STEP_SCRIPT (plchar.h), but retail branches on the second
 * facing with `bne` and the 0x41 load in the delay slot, where the macro emits
 * `beq`; the script selection needs another switch or if form. */
INCLUDE_ASM(func_801CED0C);

MATCH void func_801CEE08(void) {
    SYS_DISPATCH_TASK(D_801CFEFC, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CEE4C);

INCLUDE_ASM(func_801CF018);

INCLUDE_ASM(func_801CF124);

MATCH void func_801CF1F8(void) {
    SYS_DISPATCH_TASK(D_801CFF08, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CF23C);

#include "overlays/plchar/Char_RunStepScript.h"

MATCH void func_801CF42C(void) {
    SYS_DISPATCH_TASK(D_801CFF14, 2, g_SpadWork);
}

#include "overlays/plchar/Char_WalkStep.h"

INCLUDE_ASM(func_801CF7BC);

#include "overlays/plchar/Char_AdvanceScript.h"

INCLUDE_ASM(func_801CFA44);

#include "overlays/plchar/Char_SpawnActor.h"

/* func_801CFD20 */
#include "overlays/plchar/Char_ProbeFacingCell.h"

INCLUDE_ASM(func_801CFE54);

INCLUDE_ASM(func_801CFE98);
