#include "scena06_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F72A0(void) {
    /* Retail takes the handler index from the entry $v0; the uninitialised local reads it. */
    u32 index;

    /* FAKE: without the block the scheduler hoists the index shift above the
       ra store (84.46%); the lock restores the retail order (99.85%). */
    ORDER_LOCK(D_801FE3D8[index]());
}

MATCH void func_801F72D4(void) {
    func_801FD29C();
    D_80146872 = 1;
}

INCLUDE_ASM(func_801F7300);

MATCH void func_801F7A00(void) {
    SYS_DISPATCH_BYTE(D_801FE3E4, D_80146874);
}

MATCH void func_801F7A3C(void) {
}

INCLUDE_ASM(func_801F7A44);

INCLUDE_ASM(func_801F7C6C);

INCLUDE_ASM(func_801F8188);

INCLUDE_ASM(func_801F8B50);

INCLUDE_ASM(func_801F8F18);

INCLUDE_ASM(func_801F90C0);

INCLUDE_ASM(func_801F97C0);

INCLUDE_ASM(func_801F9DF4);

INCLUDE_ASM(func_801FA3D0);

INCLUDE_ASM(func_801FA760);

INCLUDE_ASM(func_801FA8EC);

INCLUDE_ASM(func_801FAB08);

INCLUDE_ASM(func_801FB014);

INCLUDE_ASM(func_801FB30C);

INCLUDE_ASM(func_801FBC88);

INCLUDE_ASM(func_801FBD88);

INCLUDE_ASM(func_801FC498);

INCLUDE_ASM(func_801FC718);

INCLUDE_ASM(func_801FCB80);

INCLUDE_ASM(func_801FCD38);

MATCH void func_801FCDD0(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FE42C[index];
    handler(entity, g_SceneFlags);
}

MATCH void func_801FCE10(void) {
}

INCLUDE_ASM(func_801FCE18);

INCLUDE_ASM(func_801FCE6C);

INCLUDE_ASM(func_801FCEC0);

INCLUDE_ASM(func_801FCF30);

MATCH void func_801FCF98(void) {
    SYS_SetFlag(g_SceneFlags, 0xCU);
}

INCLUDE_ASM(func_801FCFC0);

INCLUDE_ASM(func_801FD014);

INCLUDE_ASM(func_801FD06C);

INCLUDE_ASM(func_801FD0C4);

INCLUDE_ASM(func_801FD11C);

INCLUDE_ASM(func_801FD170);

INCLUDE_ASM(func_801FD1C8);

INCLUDE_ASM(func_801FD234);

MATCH s32 func_801FD294(void) {
    return 0;
}

INCLUDE_ASM(func_801FD29C);

INCLUDE_ASM(func_801FD34C);

INCLUDE_ASM(func_801FD3BC);

INCLUDE_ASM(func_801FD568);

INCLUDE_ASM(func_801FD748);

INCLUDE_ASM(func_801FD800);

INCLUDE_ASM(func_801FDD14);

INCLUDE_ASM(func_801FDD7C);

MATCH void func_801FDE2C(void) {
}

INCLUDE_ASM(func_801FDE34);

INCLUDE_ASM(func_801FDEA4);

INCLUDE_ASM(func_801FDFFC);

INCLUDE_ASM(func_801FE048);

INCLUDE_ASM(func_801FE08C);

INCLUDE_ASM(func_801FE0D0);

MATCH void func_801FE11C(void) {
    Party_JoinMember(5);
}

MATCH void func_801FE13C(void) {
    Party_JoinMember(6);
}

MATCH void func_801FE15C(void) {
    EMI_LoaderStreamFamily(0U, 1U, 2U, 0U);
    Party_BuildBattlers(0);
    Party_JoinMember(1);
}

MATCH void func_801FE198(void) {
    EMI_LoaderStreamFamily(0U, 1U, 2U, 0U);
    Party_BuildBattlers(0);
    Party_JoinMember(2);
}

MATCH void func_801FE1D4(void) {
    EMI_LoaderStreamFamily(0U, 1U, 2U, 0U);
    Party_BuildBattlers(0);
    Party_JoinMember(1);
}

INCLUDE_ASM(func_801FE210);

MATCH void func_801FE254(void) {
    func_801C1ABC(0);
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FE284(void) {
    func_801C1ABC(0);
    func_801C1ABC(5);
    func_801C1630();
}

MATCH void func_801FE2B4(void) {
    func_801C1ABC(0);
    func_801C1ABC(6);
    func_801C1630();
}

MATCH void func_801FE2E4(void) {
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FE30C(void) {
    func_801C1ABC(6);
    func_801C1630();
}

MATCH void func_801FE334(void) {
    func_801C1ABC(6);
    func_801C1ABC(2);
    func_801C1630();
}

MATCH void func_801FE364(void) {
    func_801C1ABC(5);
    func_801C1630();
}

MATCH void func_801FE38C(void) {
    func_801C1ABC(5);
    func_801C1ABC(6);
    func_801C1630();
}
