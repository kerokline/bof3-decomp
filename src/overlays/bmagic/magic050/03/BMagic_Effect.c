#include "magic050_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

/* func_801EEC10 */
#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC70);

INCLUDE_ASM(func_801EEDF8);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEF08(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEF4C);

INCLUDE_ASM(func_801EEFDC);

INCLUDE_ASM(func_801EF0E8);

MATCH void func_801EF138(void) {
    PartyBattler* work;
    u8            count;

    work = g_SpadWork;
    work->unk_0A++;
    work         = g_SpadWork;
    count        = work->unk_09 - 1;
    work->unk_09 = count;
    if (count == 0) {
        BATTLE_ACTIVE_WORK->unk_0B--;
        func_801E5988();
    }
}

INCLUDE_ASM(func_801EF1B0);

INCLUDE_ASM(func_801EF4C4);

INCLUDE_ASM(func_801EF898);
