#include "scena04_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F6D08(void) {
    /* FAKE: retail reads the handler record from entry $v0; the pin is the
       entry-register residual (identical bytes to the unpinned 84.46%). */
    MATCH_REG(u8*, entity, "v0");

    D_801FA180[entity[1]]();
}

INCLUDE_ASM(func_801F6D44);

INCLUDE_ASM(func_801F6DD4);

INCLUDE_ASM(func_801F6EA4);

INCLUDE_ASM(func_801F6F2C);

INCLUDE_ASM(func_801F6FF8);

MATCH void func_801F7064(void) {
    Actor_Clear();
}

INCLUDE_ASM(func_801F7084);

INCLUDE_ASM(func_801F732C);

INCLUDE_ASM(func_801F747C);

INCLUDE_ASM(func_801F75BC);

MATCH void func_801F77A8(void) {
    SYS_DISPATCH_TASK(D_801FA198, 1, g_SpadWork);
}

INCLUDE_ASM(func_801F77EC);

INCLUDE_ASM(func_801F78F4);

MATCH void func_801F7A64(void) {
    Actor_Clear();
}

MATCH void func_801F7A84(void) {
    SYS_DISPATCH_TASK(D_801FA1E4, 1, g_SpadWork);
}

INCLUDE_ASM(func_801F7AC8);

INCLUDE_ASM(func_801F7B00);

INCLUDE_ASM(func_801F7BC0);

INCLUDE_ASM(func_801F7CA8);

INCLUDE_ASM(func_801F7CF0);

INCLUDE_ASM(func_801F7EC0);

MATCH void func_801F7FCC(void) {
    s32   var_v1_6;
    void* var_a0_5;

    var_a0_5 = (void*)AREA_WORK_WINDOW;
    var_v1_6 = 0;
    do {
        FIELD(s8, var_a0_5, 0x25u) = 0;
        var_v1_6 += 1;
        var_a0_5 += 0x28;
    } while ((u32)(var_v1_6 & BYTE_MASK) < 0x80U);
}

INCLUDE_ASM(func_801F7FF8);

INCLUDE_ASM(func_801F8034);

MATCH void func_801F8124(void) {
    SYS_DISPATCH_BYTE(D_801FA204, D_80146872);
}

MATCH void func_801F8160(void) {
    D_80146872 = 1;
    D_80144EA8 = 0;
}

INCLUDE_ASM(func_801F817C);

MATCH void func_801F863C(void) {
    SYS_DISPATCH_BYTE(D_801FA210, g_SceneState.state_04);
}

MATCH void func_801F8678(void) {
}

INCLUDE_ASM(func_801F8680);

INCLUDE_ASM(func_801F8F98);

MATCH void func_801F9CFC(void) {
    s32 offset = D_801FA220[(g_FrameCount >> 1) & 3];

    g_AreaViewRefreshCount = 2;
    g_AreaCameraHeight += offset * 4;
}

MATCH void func_801F9D48(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FA224[index];
    handler(entity, g_SceneFlags);
}

INCLUDE_ASM(func_801F9D88);

MATCH s32 func_801F9DAC(void) {
    return 0;
}

INCLUDE_ASM(func_801F9DB4);

INCLUDE_ASM(func_801F9DF4);

MATCH s32 Scene_ShowMessage(s32 message_index) {
    Message_StartAreaMessage(message_index & BYTE_MASK);
    g_GameStateIndex = GAME_REQUEST_MESSAGE;
    g_GameFlags |= GAME_FLAG_SCRIPT_ACTIVE;
    return 1;
}

INCLUDE_ASM(func_801FA010);

MATCH void func_801FA074(void) {
    Game_SetScriptActive();
    D_80146876            = 0xA;
    g_SceneState.state_04 = 2;
    g_SceneState.step_05  = 0;
}

INCLUDE_ASM(func_801FA0B4);

INCLUDE_ASM(func_801FA12C);

MATCH void func_801FA178(void) {
}
