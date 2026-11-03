#include "sce15ef2_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

INCLUDE_ASM(func_801D0C0C);

INCLUDE_ASM(func_801D0C70);

INCLUDE_ASM(func_801D0CA0);

INCLUDE_ASM(func_801D0D00);

INCLUDE_ASM(func_801D0D5C);

MATCH void func_801D0DA4(void) {
    SYS_DISPATCH_TASK(D_801D1B2C, 1, g_SpadWork);
}

INCLUDE_ASM(func_801D0DE8);

INCLUDE_ASM(func_801D0E30);

MATCH void func_801D0EC4(void) {
    if (!(func_801D1624(0xF0) & BYTE_MASK)) {
        Actor_Clear();
    }
}

INCLUDE_ASM(func_801D0EF8);

INCLUDE_ASM(func_801D0F68);

INCLUDE_ASM(func_801D0F9C);

INCLUDE_ASM(func_801D1008);

INCLUDE_ASM(func_801D1050);

MATCH void func_801D10A4(void) {
    SYS_DISPATCH_TASK(D_801D1B48, 1, g_SpadWork);
}

INCLUDE_ASM(func_801D10E8);

INCLUDE_ASM(func_801D1118);

INCLUDE_ASM(func_801D11A4);

INCLUDE_ASM(func_801D1218);

INCLUDE_ASM(func_801D1414);

MATCH void func_801D15B0(void) {
    s32 var_v1_6;
    s8* var_a0_5;

    var_a0_5 = (s8*)AREA_WORK_WINDOW;
    var_v1_6 = 0;
    do {
        *var_a0_5 = 0;
        var_v1_6 += 1;
        var_a0_5 += 6;
    } while ((u32)(var_v1_6 & BYTE_MASK) < 0x10U);
}

INCLUDE_ASM(func_801D15DC);

/* Walks the 16 six-byte slots at 0x800E4800 and returns 1 when one is active. A slot in state 0 takes `countdown` into its
 * halfword at +2; in state 2 that halfword drops by 8 per call and the slot is released once it goes negative. */
INCLUDE_ASM(func_801D1624);

INCLUDE_ASM(func_801D17A0);

INCLUDE_ASM(func_801D19A8);
