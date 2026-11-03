#include "scena08_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801F6F50(void) {
    /* FAKE: retail reads the handler record from entry $v0; the pin is the
       entry-register residual (identical bytes to the unpinned 84.46%). */
    MATCH_REG(u8*, entity, "v0");

    D_801FE894[entity[1]]();
}

INCLUDE_ASM(func_801F6F8C);

INCLUDE_ASM(func_801F6FC4);

MATCH void func_801F7048(void) {
    if (func_801F7E14() & BYTE_MASK) {
        Actor_Clear();
    }
}

MATCH void func_801F707C(void) {
    SYS_DISPATCH_TASK(D_801FE8A0, 1, g_SpadWork);
}

INCLUDE_ASM(func_801F70C0);

INCLUDE_ASM(func_801F7164);

INCLUDE_ASM(func_801F7200);

INCLUDE_ASM(func_801F7268);

INCLUDE_ASM(func_801F7320);

INCLUDE_ASM(func_801F73D4);

INCLUDE_ASM(func_801F743C);

INCLUDE_ASM(func_801F74E0);

INCLUDE_ASM(func_801F757C);

INCLUDE_ASM(func_801F75E4);

INCLUDE_ASM(func_801F7688);

INCLUDE_ASM(func_801F774C);

INCLUDE_ASM(func_801F77B4);

MATCH void func_801F7928(void) {
    SYS_DISPATCH_TASK(D_801FE8D0, 1, g_SpadWork);
}

MATCH void func_801F796C(void) {
    SYS_DISPATCH_TASK(D_801FE8D8, 2, g_SpadWork);
}

INCLUDE_ASM(func_801F79B0);

INCLUDE_ASM(func_801F79EC);

MATCH void func_801F7A9C(void) {
    if (!(func_801F8BF8() & BYTE_MASK)) {
        Actor_Clear();
    }
}

INCLUDE_ASM(func_801F7AD0);

INCLUDE_ASM(func_801F7B2C);

INCLUDE_ASM(func_801F7BA8);

INCLUDE_ASM(func_801F7C08);

INCLUDE_ASM(func_801F7C98);

INCLUDE_ASM(func_801F7CF8);

INCLUDE_ASM(func_801F7D54);

INCLUDE_ASM(func_801F7DAC);

MATCH void func_801F7DE8(void) {
    s32 var_v1_6;
    s8* var_a0_5;

    var_a0_5 = (s8*)AREA_WORK_WINDOW;
    var_v1_6 = 0;
    do {
        *var_a0_5 = 0;
        var_v1_6 += 1;
        var_a0_5 += 0x28;
    } while ((u32)(var_v1_6 & BYTE_MASK) < 0x40U);
}

INCLUDE_ASM(func_801F7E14);

INCLUDE_ASM(func_801F802C);

INCLUDE_ASM(func_801F8108);

INCLUDE_ASM(func_801F81F4);

INCLUDE_ASM(func_801F823C);

INCLUDE_ASM(func_801F8534);

INCLUDE_ASM(func_801F85F0);

INCLUDE_ASM(func_801F8964);

MATCH void func_801F8AE8(void) {
    s32 var_v1_6;
    s8* var_a0_5;

    var_a0_5 = (s8*)AREA_WORK_WINDOW;
    var_v1_6 = 0;
    do {
        *var_a0_5 = 0;
        var_v1_6 += 1;
        var_a0_5 += 0x1C;
    } while ((u32)(var_v1_6 & BYTE_MASK) < 8U);
}

INCLUDE_ASM(func_801F8B14);

INCLUDE_ASM(func_801F8B50);

INCLUDE_ASM(func_801F8BF8);

INCLUDE_ASM(func_801F8CDC);

#include "overlays/scenario/Actor_WaitAndStep.h"

INCLUDE_ASM(func_801F8D4C);

INCLUDE_ASM(func_801F8D98);

INCLUDE_ASM(func_801F90C8);

#include "shared/AngleAverage12.h"

INCLUDE_ASM(func_801F9470);

MATCH void func_801F95D4(void) {
    SYS_DISPATCH_TASK(D_801FE908, 1, g_SpadWork);
}

INCLUDE_ASM(func_801F9618);

MATCH void func_801F9668(void) {
    Actor_Clear();
}

INCLUDE_ASM(func_801F9688);

MATCH void func_801F986C(void) {
    SYS_DISPATCH_TASK(D_801FE910, 1, g_SpadWork);
}

/* Stores 60 in byte 9 and increments byte 1 of the scratchpad buffer at slots[0x11]. */
MATCH void func_801F98B0(void) {
    void** slots;
    void*  sp_ptr;

    slots            = SP_PTR(void*, 0u);
    sp_ptr           = slots[0x11];
    ((u8*)sp_ptr)[9] = 0x3C;
    sp_ptr           = slots[0x11];
    ((u8*)sp_ptr)[1]++;
}

INCLUDE_ASM(func_801F98E0);

INCLUDE_ASM(func_801F995C);

INCLUDE_ASM(func_801F9A10);

INCLUDE_ASM(func_801F9AC0);

INCLUDE_ASM(func_801F9B68);

INCLUDE_ASM(func_801F9C00);

INCLUDE_ASM(func_801F9C58);

INCLUDE_ASM(func_801F9CE0);

INCLUDE_ASM(func_801F9D30);

MATCH void func_801F9DBC(void) {
    SYS_DISPATCH_TASK(D_801FE938, 1, g_SpadWork);
}

INCLUDE_ASM(func_801F9E00);

INCLUDE_ASM(func_801F9E50);

INCLUDE_ASM(func_801F9EC4);

MATCH void func_801F9F2C(void) {
    Scene_AdvanceActorStep();
}

MATCH void func_801F9F4C(void) {
    Scene_AdvanceActorStep();
}

MATCH void func_801F9F6C(void) {
    Actor_Clear();
}

INCLUDE_ASM(func_801F9F8C);

INCLUDE_ASM(func_801FA19C);

MATCH void func_801FA294(void) {
    SYS_DISPATCH_BYTE(D_801FE964, D_80146872);
}

INCLUDE_ASM(func_801FA2D0);

INCLUDE_ASM(func_801FA32C);

INCLUDE_ASM(func_801FA3E4);

MATCH void func_801FAB5C(void) {
    SYS_DISPATCH_BYTE(D_801FE970, g_SceneState.state_04);
}

MATCH void func_801FAB98(void) {
}

INCLUDE_ASM(func_801FABA0);

INCLUDE_ASM(func_801FB168);

INCLUDE_ASM(func_801FB270);

INCLUDE_ASM(func_801FB8A0);

INCLUDE_ASM(func_801FBA70);

INCLUDE_ASM(func_801FBCA4);

INCLUDE_ASM(func_801FC21C);

INCLUDE_ASM(func_801FC45C);

INCLUDE_ASM(func_801FD07C);

INCLUDE_ASM(func_801FD1A4);

INCLUDE_ASM(func_801FD400);

INCLUDE_ASM(func_801FD704);

INCLUDE_ASM(func_801FDF84);

MATCH void func_801FE018(void* entity) {
    SceneFunc handler;
    u8        index;

    index   = ((Actor*)entity)->callback_index;
    handler = D_801FE9C0[index];
    handler(entity, g_SceneFlags);
}

INCLUDE_ASM(func_801FE058);

MATCH void func_801FE0A0(void) {
    g_ScriptVars[0] = 0;
    Game_SetScriptActive();
    g_SceneState.state_04 = 7;
    g_SceneState.step_05  = 0xA;
}

INCLUDE_ASM(func_801FE0E0);

INCLUDE_ASM(func_801FE12C);

INCLUDE_ASM(func_801FE170);

INCLUDE_ASM(func_801FE2A0);

INCLUDE_ASM(func_801FE698);

INCLUDE_ASM(func_801FE6DC);

MATCH void func_801FE740(void) {
    Party_JoinMember(2);
}

INCLUDE_ASM(func_801FE760);

INCLUDE_ASM(func_801FE7AC);

INCLUDE_ASM(func_801FE800);

MATCH void func_801FE840(void) {
    EMI_LoaderStreamFamily(7U, 8U, 4U, 0U);
    func_801FE800();
}

MATCH void func_801FE874(void) {
    func_801C1ABC(2);
}
