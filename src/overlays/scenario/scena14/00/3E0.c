#include "scena14_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F6FE0(void) {
    /* Retail takes the handler index from the entry $v0; the uninitialised local reads it. */
    u32 index;

    /* FAKE: without the block the scheduler hoists the index shift above the
       ra store (84.46%); the lock restores the retail order (99.85%). */
    ORDER_LOCK(D_801FC418[index]());
}

MATCH void func_801F7014(void) {
    D_80146872 = 1;
}

INCLUDE_ASM(func_801F7028);

INCLUDE_ASM(func_801F7960);

INCLUDE_ASM(func_801F7A18);

MATCH void func_801F7B5C(void) {
    SYS_DISPATCH_BYTE(D_801FC424, g_SceneState.state_04);
}

MATCH void func_801F7B98(void) {
}

INCLUDE_ASM(func_801F7BA0);

INCLUDE_ASM(func_801F7FB8);

INCLUDE_ASM(func_801F8800);

INCLUDE_ASM(func_801F8850);

INCLUDE_ASM(func_801F88DC);

INCLUDE_ASM(func_801F8CE4);

INCLUDE_ASM(func_801F924C);

INCLUDE_ASM(func_801F9320);

INCLUDE_ASM(func_801F9834);

INCLUDE_ASM(func_801FA904);

INCLUDE_ASM(func_801FA9C8);

MATCH void func_801FB374(void) {
}

MATCH void func_801FB37C(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FC468[index];
    handler(entity, g_SceneFlags);
}

INCLUDE_ASM(func_801FB3BC);

INCLUDE_ASM(func_801FB414);

INCLUDE_ASM(func_801FB46C);

INCLUDE_ASM(func_801FB4C4);

INCLUDE_ASM(func_801FB51C);

MATCH void func_801FB574(void) {
    Game_SetScriptActive();
    g_SceneState.state_04 = 5;
    g_SceneState.step_05  = 5;
}

INCLUDE_ASM(func_801FB5A8);

INCLUDE_ASM(func_801FB5F8);

INCLUDE_ASM(func_801FB648);

INCLUDE_ASM(func_801FB84C);

INCLUDE_ASM(func_801FBD2C);

INCLUDE_ASM(func_801FBD78);

INCLUDE_ASM(func_801FBDC4);

INCLUDE_ASM(func_801FBE10);

INCLUDE_ASM(func_801FBF18);

INCLUDE_ASM(func_801FBFA8);

INCLUDE_ASM(func_801FC020);

INCLUDE_ASM(func_801FC074);

INCLUDE_ASM(func_801FC0C8);

INCLUDE_ASM(func_801FC130);

INCLUDE_ASM(func_801FC1E8);

INCLUDE_ASM(func_801FC22C);

INCLUDE_ASM(func_801FC280);

INCLUDE_ASM(func_801FC328);
