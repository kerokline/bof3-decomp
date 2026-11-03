#include "scena11_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F70BC(void) {
    /* FAKE: retail reads the handler record from entry $v0; the pin is the
       entry-register residual (identical bytes to the unpinned 84.46%). */
    MATCH_REG(u8*, entity, "v0");

    D_801FAEC0[entity[1]]();
    g_AreaViewRefreshCount = 2;
}

INCLUDE_ASM(func_801F7104);

INCLUDE_ASM(func_801F7178);

INCLUDE_ASM(func_801F7200);

MATCH void func_801F7288(void) {
    SYS_DISPATCH_BYTE(D_801FAEF0, D_80146872);
}

MATCH void func_801F72C4(void) {
    g_AreaDrawFlags = AREA_DRAW_ALL_FLAGS;
    D_80146872      = 1;
}

INCLUDE_ASM(func_801F72E4);

MATCH void func_801F7748(void) {
    SYS_DISPATCH_BYTE(D_801FAEFC, D_80146874);
}

MATCH void func_801F7784(void) {
}

INCLUDE_ASM(func_801F778C);

INCLUDE_ASM(func_801F7BFC);

INCLUDE_ASM(func_801F7CC8);

INCLUDE_ASM(func_801F7F08);

INCLUDE_ASM(func_801F82D8);

INCLUDE_ASM(func_801F83C8);

/* Stores GAME_REQUEST_STATUS_MENU to g_GameStateIndex (at 0x801F8D2C). */
INCLUDE_ASM(func_801F8B84);

MATCH void func_801F917C(void) {
}

INCLUDE_ASM(func_801F9184);

INCLUDE_ASM(func_801FA3A4);

MATCH void func_801FA5B8(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FAF24[index];
    handler(entity, g_SceneFlags);
}

MATCH void func_801FA5F8(void) {
}

INCLUDE_ASM(func_801FA600);

INCLUDE_ASM(func_801FA674);

INCLUDE_ASM(func_801FA6C0);

MATCH void func_801FA70C(void) {
    Game_SetScriptActive();
    D_80146875 = 0xa;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 3;
}

INCLUDE_ASM(func_801FA75C);

INCLUDE_ASM(func_801FA7A8);

INCLUDE_ASM(func_801FA7F4);

MATCH void func_801FA840(void) {
    Game_SetScriptActive();
    D_80146875 = 5;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 9;
}

MATCH void func_801FA890(void) {
    Game_SetScriptActive();
    D_80146875 = 0x14;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 0xa;
}

MATCH void func_801FA8E0(void) {
    Game_SetScriptActive();
    D_80146875 = 0x14;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 0xb;
}

INCLUDE_ASM(func_801FA930);

INCLUDE_ASM(func_801FA988);

MATCH void func_801FA9D4(void) {
    Game_SetScriptActive();
    D_80146875 = 0x1e;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 0xe;
}

MATCH void func_801FAA24(void) {
    Game_SetScriptActive();
    D_80146875 = 0x28;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 5;
}

INCLUDE_ASM(func_801FAA74);

MATCH s32 func_801FAB64(void) {
    return 0;
}

MATCH s32 func_801FAB6C(void) {
    return -1;
}

INCLUDE_ASM(func_801FAB74);

INCLUDE_ASM(func_801FABC0);

INCLUDE_ASM(func_801FAC04);

INCLUDE_ASM(func_801FAC48);

INCLUDE_ASM(func_801FAC94);

INCLUDE_ASM(func_801FACD8);

INCLUDE_ASM(func_801FAD1C);

INCLUDE_ASM(func_801FAD68);

INCLUDE_ASM(func_801FADAC);

MATCH void func_801FADF8(void) {
    func_801C1ABC(4);
    func_801C1630();
}

MATCH void func_801FAE20(void) {
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FAE48(void) {
    func_801C1ABC(6);
    func_801C1630();
}

MATCH void func_801FAE70(void) {
    func_801C1ABC(5);
    func_801C1630();
}

MATCH void func_801FAE98(void) {
    func_801C1ABC(8);
    func_801C1630();
}
