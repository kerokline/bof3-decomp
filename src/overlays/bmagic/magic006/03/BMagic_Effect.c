#include "magic006_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC38(void) {
    Bmagic_DispatchTaskPair(func_801EEC90, func_801EEDA4);
}

INCLUDE_ASM(func_801EEC90);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEE04(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEE48);

INCLUDE_ASM(func_801EEF28);

INCLUDE_ASM(func_801EF04C);

INCLUDE_ASM(func_801EF0B8);

INCLUDE_ASM(func_801EF118);

INCLUDE_ASM(func_801EF298);

#include "overlays/bmagic/Effect_TickOnTimerZero.h"

INCLUDE_ASM(func_801EF478);

INCLUDE_ASM(func_801EFB6C);

INCLUDE_ASM(func_801F0064);

INCLUDE_ASM(func_801F0100);

INCLUDE_ASM(func_801F020C);

#include "overlays/bmagic/Effect_CountDownTimer.h"

INCLUDE_ASM(func_801F0308);

INCLUDE_ASM(func_801F04F4);

INCLUDE_ASM(func_801F05A4);

MATCH void func_801F05F4(void) {
    u8 timer;

    timer              = g_SpadWork->unk_09 + 4;
    g_SpadWork->unk_09 = timer;
    if (timer == 16) {
        g_SpadWork->unk_02 = g_SpadWork->unk_02 + 1;
    }
}

#include "overlays/bmagic/Effect_NextStepOnLastTick.h"

MATCH void Effect_TickOnTimerZero_801F0684(void) {
    PartyBattler* work;

    BMAGIC_TICK_ON_TIMER_ZERO();
}

#include "overlays/bmagic/Effect_SetActorMatrix.h"

INCLUDE_ASM(func_801F0790);
