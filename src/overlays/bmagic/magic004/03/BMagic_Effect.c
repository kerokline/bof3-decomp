#include "magic004_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC28(void) {
    BattleHandlerTable5 handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC98);

INCLUDE_ASM(func_801EEF8C);

INCLUDE_ASM(func_801EF158);

INCLUDE_ASM(func_801EF1F0);

INCLUDE_ASM(func_801EF3E0);

INCLUDE_ASM(func_801EF490);

INCLUDE_ASM(func_801EF6E0);

MATCH void func_801EF8CC(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF910);

#include "overlays/bmagic/Effect_ReloadTimerAndStep.h"

INCLUDE_ASM(func_801EF9E8);

MATCH void func_801EFA70(void) {
    if (func_8014DAEC() & BYTE_MASK) {
        BATTLE_ACTIVE_WORK->unk_0B--;
        g_SpadWork->unk_02++;
    }
}

MATCH void func_801EFAD4(void) {
    func_801E5988();
}

INCLUDE_ASM(func_801EFAF4);

#include "overlays/bmagic/Effect_StepWhileTickUnderTwo.h"

INCLUDE_ASM(func_801EFBEC);

INCLUDE_ASM(func_801EFD84);
