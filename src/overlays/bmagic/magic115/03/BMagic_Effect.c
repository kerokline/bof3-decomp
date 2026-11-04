#include "magic115_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC14(void) {
    MagicTaskFuncs handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC80);

INCLUDE_ASM(func_801EEDDC);

INCLUDE_ASM(func_801EEEB0);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EF054(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF098);

INCLUDE_ASM(func_801EF130);

INCLUDE_ASM(func_801EF27C);

INCLUDE_ASM(func_801EF49C);

MATCH void func_801EF5C4(void) {
    BMAGIC_TICK_EFFECT_WORK();
    func_801E5988();
}

INCLUDE_ASM(func_801EF5F8);

INCLUDE_ASM(func_801EF690);

MATCH void func_801EF7A4(void) {
    func_8014DAEC();
    if (func_8014DAEC() != 0u) {
        g_SpadWork->unk_02 = g_SpadWork->unk_02 + 2;
    }
}

INCLUDE_ASM(func_801EF7F4);

MATCH void func_801EF888(void) {
    BMAGIC_TICK_EFFECT_WORK();
    func_801E5988();
}
