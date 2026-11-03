#include "magic039_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC94);

MATCH void func_801EEEA8(void) {
    PartyBattler* work;

    work = SP_REF(PartyBattler*, 0x44u);
    if (work->unk_0B == 0) {
        work->step_01 = work->step_01 + 1;
    }
}

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

INCLUDE_ASM(func_801EEF3C);

MATCH void func_801EEF64(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEFA8);

INCLUDE_ASM(func_801EF070);

INCLUDE_ASM(func_801EF0D4);

INCLUDE_ASM(func_801EF134);

INCLUDE_ASM(func_801EF1F4);

INCLUDE_ASM(func_801EF320);

INCLUDE_ASM(func_801EF44C);

INCLUDE_ASM(func_801EF4E4);

INCLUDE_ASM(func_801EF584);

MATCH void func_801EF690(void) {
    u8 timer;

    timer              = g_SpadWork->unk_09 + 16;
    g_SpadWork->unk_09 = timer;
    if (timer == 128) {
        g_SpadWork->unk_02 = g_SpadWork->unk_02 + 1;
    }
}

#include "overlays/bmagic/Effect_CountDownTimer.h"

INCLUDE_ASM(func_801EF758);

#include "overlays/bmagic/Effect_SetActorMatrix.h"

INCLUDE_ASM(func_801EFAA4);

INCLUDE_ASM(func_801F0054);
