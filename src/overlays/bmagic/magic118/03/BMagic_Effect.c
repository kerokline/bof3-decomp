#include "magic118_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC18(void) {
    BattleHandlerTable5 handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_BYTE(handlers.handlers, g_SpadWork->step_01);
    if (g_SpadWork->flags_00 != 0 && g_SpadWork->step_01 != 0) {
        Effect_SetActorMatrix();
        func_801EF6BC();
        func_801EFA1C();
        PopMatrix();
    }
}

INCLUDE_ASM(func_801EECD4);

MATCH void func_801EEE20(void) {
    u8 timer;

    timer              = g_SpadWork->unk_09 + 1;
    g_SpadWork->unk_09 = timer;
    if (timer == 16) {
        func_800A9610(g_BattleTargetSelector, 0x10);
        g_SpadWork->step_01 = g_SpadWork->step_01 + 1;
    }
}

MATCH void func_801EEE8C(void) {
    PartyBattler* work;

    work = SP_REF(PartyBattler*, 0x44u);
    if (work->unk_0B == 1) {
        work->step_01 = work->step_01 + 1;
    }
}

#include "overlays/bmagic/Effect_CountDownTimerNextStep.h"

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

INCLUDE_ASM(func_801EEF6C);

INCLUDE_ASM(func_801EEFF4);

INCLUDE_ASM(func_801EF0A4);

INCLUDE_ASM(func_801EF108);

INCLUDE_ASM(func_801EF194);

#include "overlays/bmagic/Effect_SetActorMatrix.h"

INCLUDE_ASM(func_801EF6BC);

INCLUDE_ASM(func_801EFA1C);
