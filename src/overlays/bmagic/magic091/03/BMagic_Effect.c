#include "magic091_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

INCLUDE_ASM(func_801EEC10);

INCLUDE_ASM(func_801EECCC);

MATCH void func_801EEE3C(void) {
    g_SpadWork->unk_09 += 1;
    g_SpadWork->unk_0A += 1;
    if (g_SpadWork->unk_09 == 0x10) {
        g_SpadWork->step_01 = g_SpadWork->step_01 + 1;
    }
}

INCLUDE_ASM(func_801EEEA8);

MATCH void func_801EEF74(void) {
    SYS_DISPATCH_BYTE(D_801EFC64, ((u8*)g_SpadWork)[1]);
    if (g_SpadWork->flags_00 != 0 && ((u8*)g_SpadWork)[1] != 0) {
        Effect_SetActorMatrix();
        func_801EF240();
        PopMatrix();
    }
}

INCLUDE_ASM(func_801EEFFC);

INCLUDE_ASM(func_801EF09C);

INCLUDE_ASM(func_801EF124);

INCLUDE_ASM(func_801EF1B8);

INCLUDE_ASM(func_801EF240);

#include "overlays/bmagic/Effect_SetActorMatrix.h"

INCLUDE_ASM(func_801EF7B0);

INCLUDE_ASM(func_801EF9E4);
