#include "magic012_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Bmagic_DispatchTaskPair(func_801EEC5C, func_801EEEAC);
}

INCLUDE_ASM(func_801EEC5C);

INCLUDE_ASM(func_801EEEAC);

MATCH void func_801EEFF8(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

MATCH void func_801EF03C(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectFuncs + 1), 2, g_SpadWork);
}

INCLUDE_ASM(func_801EF080);

INCLUDE_ASM(func_801EF188);

INCLUDE_ASM(func_801EF3C4);

INCLUDE_ASM(func_801EF4B8);

MATCH void func_801EF670(void) {
    BMAGIC_TICK_EFFECT_WORK();
    func_801E5988();
}

INCLUDE_ASM(func_801EF6A4);

INCLUDE_ASM(func_801EF79C);
