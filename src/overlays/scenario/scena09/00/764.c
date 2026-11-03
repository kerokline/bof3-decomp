#include "scena09_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F7364(void) {
    /* FAKE: retail reads the handler record from entry $v0; the pin is the
       entry-register residual (identical bytes to the unpinned 84.46%). */
    MATCH_REG(u8*, entity, "v0");

    D_801FE384[entity[1]]();
}

INCLUDE_ASM(func_801F73A0);

MATCH void func_801F73F0(void) {
    if (!(func_801F75BC() & BYTE_MASK)) {
        Actor_Clear();
    }
}

INCLUDE_ASM(func_801F7424);

INCLUDE_ASM(func_801F7574);

INCLUDE_ASM(func_801F75BC);

INCLUDE_ASM(func_801F76D0);

MATCH void func_801F78D0(void) {
    SYS_DISPATCH_BYTE(D_801FE3E0, D_80146872);
}

MATCH void func_801F790C(void) {
    D_80146872 = 1;
}

INCLUDE_ASM(func_801F7920);

MATCH void func_801F83D8(void) {
    SYS_DISPATCH_BYTE(D_801FE3EC, D_80146874);
}

MATCH void func_801F8414(void) {
}

INCLUDE_ASM(func_801F841C);

INCLUDE_ASM(func_801F8504);

INCLUDE_ASM(func_801F8770);

INCLUDE_ASM(func_801F8D30);

INCLUDE_ASM(func_801F9354);

INCLUDE_ASM(func_801F9498);

INCLUDE_ASM(func_801FA08C);

INCLUDE_ASM(func_801FA1F0);

INCLUDE_ASM(func_801FA8B8);

INCLUDE_ASM(func_801FAC88);

INCLUDE_ASM(func_801FAE0C);

INCLUDE_ASM(func_801FBC78);

INCLUDE_ASM(func_801FBD0C);

INCLUDE_ASM(func_801FBD6C);

MATCH void func_801FC588(void) {
}

INCLUDE_ASM(func_801FC590);

MATCH void func_801FC5DC(void) {
}

MATCH void func_801FC5E4(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FE434[index];
    handler(entity, g_SceneFlags);
}

MATCH void func_801FC624(void) {
}

MATCH void func_801FC62C(void) {
    Game_SetScriptActive();
    g_ScriptVars = 0;
    D_80146875   = 0;
    D_80146874   = 5;
}

MATCH void func_801FC668(void) {
    Game_SetScriptActive();
    g_ScriptVars = 0;
    D_80146875   = 5;
    D_80146874   = 5;
}

MATCH void func_801FC6A4(void) {
    Game_SetScriptActive();
    D_80146875 = 5;
    D_80146874 = 4;
}

MATCH void func_801FC6DC(void) {
    Game_SetScriptActive();
    D_80146874 = 0xA;
    D_80146875 = 0;
}

MATCH void func_801FC710(void) {
    Game_SetScriptActive();
    D_80146874 = 0xA;
    D_80146875 = 1;
}

MATCH void func_801FC748(void) {
    *SP_REF(s8*, 0x44) = 0;
    Game_SetScriptActive();
    D_80146874 = 0xD;
    D_80146875 = 5;
}

MATCH void func_801FC788(void) {
    SYS_SetFlag(g_SceneFlags, 0xEU);
}

MATCH void func_801FC7B0(void) {
    Game_SetScriptActive();
    D_80146874 = 6;
    D_80146875 = 0x64;
}

MATCH void func_801FC7E8(void) {
    SYS_SetFlag(g_SceneFlags, 0x10U);
}

MATCH void func_801FC810(void) {
    SYS_SetFlag(g_SceneFlags, 0x14U);
}

MATCH void func_801FC838(void) {
    Game_SetScriptActive();
    D_80146874 = 8;
    D_80146875 = 0xF;
}

MATCH void func_801FC870(void) {
}

MATCH void func_801FC878(void) {
    Game_SetScriptActive();
    D_80146874 = 0xF;
    D_80146875 = 0;
}

MATCH void func_801FC8AC(void) {
    Game_SetScriptActive();
    D_80146874 = 0xF;
    D_80146875 = 0x14;
}

MATCH void func_801FC8E4(void) {
    Game_SetScriptActive();
    D_80146874 = 0xF;
    D_80146875 = 0x28;
}

INCLUDE_ASM(func_801FC91C);

MATCH s32 func_801FD278(void) {
    return 0;
}

INCLUDE_ASM(func_801FD280);

INCLUDE_ASM(func_801FD2E8);

INCLUDE_ASM(func_801FD388);

INCLUDE_ASM(func_801FD498);

INCLUDE_ASM(func_801FD5A8);

INCLUDE_ASM(func_801FD6F8);

INCLUDE_ASM(func_801FD7F4);

INCLUDE_ASM(func_801FD8F0);

INCLUDE_ASM(func_801FD978);

INCLUDE_ASM(func_801FDA04);

INCLUDE_ASM(func_801FDA90);

INCLUDE_ASM(func_801FDB1C);

INCLUDE_ASM(func_801FDBA8);

INCLUDE_ASM(func_801FDC1C);

INCLUDE_ASM(func_801FDC70);

INCLUDE_ASM(func_801FDCF4);

INCLUDE_ASM(func_801FDD38);

INCLUDE_ASM(func_801FDD7C);

INCLUDE_ASM(func_801FDDC8);

INCLUDE_ASM(func_801FDE0C);

MATCH void func_801FDE50(void) {
    Party_BuildBattlers(0);
    Party_JoinMember(6);
    func_801C1630();
}

INCLUDE_ASM(func_801FDE80);

INCLUDE_ASM(func_801FDECC);

INCLUDE_ASM(func_801FDF10);

INCLUDE_ASM(func_801FDF54);

INCLUDE_ASM(func_801FE014);

INCLUDE_ASM(func_801FE058);

INCLUDE_ASM(func_801FE0A4);

INCLUDE_ASM(func_801FE0E8);

MATCH void func_801FE12C(void) {
    func_801C1ABC(4);
    func_801C1630();
}

MATCH void func_801FE154(void) {
    func_801C1ABC(4);
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FE184(void) {
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FE1AC(void) {
    func_801C1ABC(2);
    func_801C1ABC(8);
    func_801C1630();
}

MATCH void func_801FE1DC(void) {
    func_801C1ABC(4);
    func_801C1ABC(8);
    func_801C1630();
}

MATCH void func_801FE20C(void) {
    func_801C1ABC(8);
    func_801C1630();
}

INCLUDE_ASM(func_801FE234);

MATCH void func_801FE30C(void) {
    func_801C1ABC(5);
    func_801C1630();
}

MATCH void func_801FE334(void) {
    func_801C1ABC(6);
    func_801C1630();
}

MATCH void func_801FE35C(void) {
    func_801C1ABC(7);
    func_801C1630();
}
