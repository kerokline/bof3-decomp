#include "magic045_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback table[2] = {func_801EEC5C, func_801EEE58};

    table[SP_REF(u8*, 0x44)[1]]();
}

INCLUDE_ASM(func_801EEC5C);

#include "overlays/bmagic/Effect_StartOnZeroTick.h"

MATCH void func_801EEEA4(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEEE8);

INCLUDE_ASM(func_801EEF80);

INCLUDE_ASM(func_801EF118);

INCLUDE_ASM(func_801EF2B0);

MATCH void func_801EF3D8(void) {
    BMAGIC_TICK_EFFECT_WORK();
    func_801E5988();
}

INCLUDE_ASM(func_801EF40C);

INCLUDE_ASM(func_801EF4A4);

INCLUDE_ASM(func_801EF608);

INCLUDE_ASM(func_801EF724);

MATCH void func_801EF8A4(void) {
    BMAGIC_TICK_EFFECT_WORK();
    func_801E5988();
}
