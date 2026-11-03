#include "scena12_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F717C(void) {
    /* FAKE: retail reads the handler record from entry $v0; the pin is the
       entry-register residual (identical bytes to the unpinned 84.46%). */
    MATCH_REG(u8*, entity, "v0");

    D_801FD178[entity[1]]();
}

MATCH void func_801F71B8(void) {
    SYS_DISPATCH_TASK(D_801FD184, 2, g_SpadWork);
}

INCLUDE_ASM(func_801F71FC);

INCLUDE_ASM(func_801F7240);

INCLUDE_ASM(func_801F7348);

MATCH void func_801F73CC(void) {
    SYS_DISPATCH_TASK(D_801FD190, 2, g_SpadWork);
}

INCLUDE_ASM(func_801F7410);

INCLUDE_ASM(func_801F7518);

INCLUDE_ASM(func_801F759C);

INCLUDE_ASM(func_801F75EC);

INCLUDE_ASM(Menu_DrawHeaderBar);

MATCH void func_801F7BA8(void) {
    SYS_DISPATCH_TASK(D_801FD198, 1, g_SpadWork);
}

MATCH void func_801F7BEC(void) {
    void* temp_v1_5;

    temp_v1_5                    = SP_REF(void*, 0x44);
    FIELD(s16, temp_v1_5, 0x2Eu) = 0;
    FIELD(u8, temp_v1_5, 0x1u)   = (u8)(FIELD(u8, temp_v1_5, 0x1u) + 1);
    SND_PlayCue(EMI_CUE_ID(2, 21));
}

INCLUDE_ASM(func_801F7C24);

MATCH void func_801F7E14(void) {
    Actor_Clear();
}

INCLUDE_ASM(func_801F7E34);

MATCH void func_801F7F28(void) {
    SYS_DISPATCH_BYTE(D_801FD1B8, D_80146872);
}

MATCH void func_801F7F64(void) {
    D_80146872 = 1;
}

INCLUDE_ASM(func_801F7F78);

MATCH void func_801F886C(void) {
    SYS_DISPATCH_BYTE(D_801FD1C4, D_80146874);
}

MATCH void func_801F88A8(void) {
}

INCLUDE_ASM(func_801F88B0);

INCLUDE_ASM(func_801F894C);

MATCH void func_801F89FC(void) {
}

INCLUDE_ASM(func_801F8A04);

INCLUDE_ASM(func_801F9680);

INCLUDE_ASM(func_801F9F0C);

INCLUDE_ASM(func_801FA7DC);

INCLUDE_ASM(func_801FAE04);

INCLUDE_ASM(func_801FB864);

MATCH void func_801FC574(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FD1EC[index];
    handler(entity, g_SceneFlags);
}

MATCH void func_801FC5B4(void) {
}

MATCH void func_801FC5BC(void) {
}

MATCH void func_801FC5C4(void) {
}

MATCH void func_801FC5CC(void) {
}

MATCH void func_801FC5D4(void) {
}

MATCH void func_801FC5DC(void) {
}

INCLUDE_ASM(func_801FC5E4);

MATCH void func_801FC630(void) {
}

MATCH void func_801FC638(void) {
}

MATCH void func_801FC640(void) {
    Game_SetScriptActive();
    D_80146875 = 0x14;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 4;
}

MATCH void func_801FC690(void) {
    Game_SetScriptActive();
    D_80146875 = 0x14;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 5;
}

INCLUDE_ASM(func_801FC6E0);

INCLUDE_ASM(func_801FC738);

MATCH void func_801FC784(void) {
    Game_SetScriptActive();
    D_80146875 = 0x1e;
    D_80146865 = 0;
    D_80146866 = 0;
    D_80146867 = 0;
    D_80146874 = 8;
}

MATCH void func_801FC7D4(void) {
    Game_SetScriptActive();
    D_80146875 = 0xA;
    D_80146874 = 1;
}

INCLUDE_ASM(func_801FC80C);

INCLUDE_ASM(func_801FC890);

INCLUDE_ASM(func_801FCC54);

INCLUDE_ASM(func_801FCCBC);

MATCH s32 func_801FCD38(void) {
    SND_PlayCue(EMI_CUE_ID(2, 9));
    return -1;
}

INCLUDE_ASM(func_801FCD58);

INCLUDE_ASM(func_801FCDE0);

INCLUDE_ASM(func_801FCE2C);

INCLUDE_ASM(func_801FCE70);

INCLUDE_ASM(func_801FCEB4);

INCLUDE_ASM(func_801FCF00);

INCLUDE_ASM(func_801FCF44);

INCLUDE_ASM(func_801FCF88);

INCLUDE_ASM(func_801FCFD4);

INCLUDE_ASM(func_801FD018);

INCLUDE_ASM(func_801FD064);

MATCH void func_801FD0B0(void) {
    func_801C1ABC(4);
    func_801C1630();
}

MATCH void func_801FD0D8(void) {
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FD100(void) {
    func_801C1ABC(6);
    func_801C1630();
}

MATCH void func_801FD128(void) {
    func_801C1ABC(5);
    func_801C1630();
}

MATCH void func_801FD150(void) {
    func_801C1ABC(8);
    func_801C1630();
}
