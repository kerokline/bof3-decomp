#include "magic065_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC24(void) {
    BattleResultRings table;

    table = D_801EEC04;
    SYS_DISPATCH_TASK(table.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC90);

INCLUDE_ASM(func_801EF08C);

INCLUDE_ASM(func_801EF134);

INCLUDE_ASM(func_801EF1CC);

MATCH void func_801EF20C(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF250);

#include "overlays/bmagic/Effect_ReloadTimerAndStep.h"

INCLUDE_ASM(func_801EF328);

INCLUDE_ASM(func_801EF394);

MATCH void func_801EF408(void) {
    func_801E5988();
}

INCLUDE_ASM(func_801EF428);
