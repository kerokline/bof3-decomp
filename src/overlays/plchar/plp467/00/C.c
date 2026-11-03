#include "plp467_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801CE404(void) {
    D_801D03AC[((u8*)g_SpadWork)[2]]();
}

MATCH void Char_StartTurn(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

#include "overlays/plchar/Char_RunStepScript.h"

MATCH void func_801CE610(void) {
    g_GameState->mode_12B.s8_value = 0;
}

MATCH void func_801CE620(void) {
    SYS_DISPATCH_TASK(D_801D03B8, 2, g_SpadWork);
}

MATCH void Char_StartTurn_801CE664(void) {
    CHAR_START_TURN(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

MATCH void Char_RunStepScript_801CE730(void) {
    CHAR_RUN_STEP_SCRIPT(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

MATCH void func_801CE82C(void) {
    func_8014D978();
}

MATCH void func_801CE84C(void) {
    SYS_DISPATCH_TASK(D_801D03C4, 2, g_SpadWork);
}

MATCH void func_801CE890(void) {
    SYS_DISPATCH_TASK(D_801D03CC, 3, g_SpadWork);
}

INCLUDE_ASM(func_801CE8D4);

INCLUDE_ASM(func_801CE9D4);

INCLUDE_ASM(func_801CEC20);

INCLUDE_ASM(func_801CED50);

INCLUDE_ASM(func_801CEDB0);

INCLUDE_ASM(func_801CEE44);

INCLUDE_ASM(func_801CF050);

MATCH void func_801CF13C(void) {
    SYS_DISPATCH_TASK(D_801D03E0, 3, g_SpadWork);
}

INCLUDE_ASM(func_801CF180);

INCLUDE_ASM(func_801CF1EC);

INCLUDE_ASM(func_801CF324);

INCLUDE_ASM(func_801CF3C0);

INCLUDE_ASM(func_801CF564);

MATCH void func_801CF6C8(void) {
    SYS_DISPATCH_TASK(D_801D03EC, 2, g_SpadWork);
}

INCLUDE_ASM(func_801CF70C);

MATCH void Char_RunStepScript_801CF800(void) {
    CHAR_RUN_STEP_SCRIPT(CHARACTER_FACING_BACK, CHARACTER_FACING_AWAY);
}

MATCH void func_801CF8FC(void) {
    SYS_DISPATCH_TASK(D_801D03F8, 2, g_SpadWork);
}

#include "overlays/plchar/Char_WalkStep.h"

INCLUDE_ASM(func_801CFC8C);

#include "overlays/plchar/Char_AdvanceScript.h"

INCLUDE_ASM(func_801CFF14);

#include "overlays/plchar/Char_SpawnActor.h"

/* func_801D01F0 */
#include "overlays/plchar/Char_ProbeFacingCell.h"

INCLUDE_ASM(func_801D0324);

INCLUDE_ASM(func_801D0368);
