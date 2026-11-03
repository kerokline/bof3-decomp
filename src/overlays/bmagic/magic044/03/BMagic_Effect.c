#include "magic044_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Bmagic_DispatchTaskPair(func_801EEC5C, func_801EEDA0);
}

INCLUDE_ASM(func_801EEC5C);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEE00(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEE44);

INCLUDE_ASM(func_801EEEFC);

INCLUDE_ASM(func_801EF138);

INCLUDE_ASM(func_801EF320);

/* Template: area125/13 func_801F2CD8 reads unk_01 of the effect struct, which this image's struct lacks; compile fails. */
INCLUDE_ASM(func_801EF478);

INCLUDE_ASM(func_801EF4E0);

INCLUDE_ASM(func_801EFA4C);

INCLUDE_ASM(func_801F02A0);

INCLUDE_ASM(func_801F0390);

MATCH void func_801F0478(void) {
    SYS_DISPATCH_BYTE(D_801F0A2C, g_SpadWork->unk_02);
    if (g_SpadWork->flags_00 != 0 && g_SpadWork->unk_02 != 0) {
        func_801F06D8();
    }
}

INCLUDE_ASM(func_801F04F0);

INCLUDE_ASM(func_801F05AC);

INCLUDE_ASM(func_801F0638);

INCLUDE_ASM(func_801F06D8);
