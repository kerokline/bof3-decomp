#include "magic154_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC24(void) {
    BattleResultRings table;

    table = D_801EEC04;
    SYS_DISPATCH_TASK(table.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC90);

INCLUDE_ASM(func_801EEE94);

INCLUDE_ASM(func_801EEFE0);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EF0C0(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF104);

INCLUDE_ASM(func_801EF1EC);

INCLUDE_ASM(func_801EF380);

INCLUDE_ASM(func_801EF3E4);

INCLUDE_ASM(func_801EF454);

INCLUDE_ASM(func_801EF4B4);

#include "overlays/bmagic/Effect_ReloadTimerAndStep.h"

INCLUDE_ASM(func_801EF58C);

INCLUDE_ASM(func_801EF648);

MATCH void func_801EF6AC(void) {
    func_801E5988();
}
