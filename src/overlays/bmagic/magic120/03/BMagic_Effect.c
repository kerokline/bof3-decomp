#include "magic120_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC70);

INCLUDE_ASM(func_801EEEC8);

#include "overlays/bmagic/Effect_PlayOnIdleTick.h"

MATCH void func_801EF010(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF054);

INCLUDE_ASM(func_801EF0D8);

INCLUDE_ASM(func_801EF270);

MATCH void func_801EF2EC(void) {
    PartyBattler* work;
    u8            timer;

    work         = g_SpadWork;
    work->unk_0B = work->unk_0B - 1;
    work         = g_SpadWork;
    timer        = work->unk_09 + 1;
    work->unk_09 = timer;
    if (timer == 24) {
        func_800A9610(g_BattleTargetSelector, 0x10);
        work         = g_SpadWork;
        work->unk_02 = work->unk_02 + 1;
    }
}

MATCH void func_801EF374(void) {
    u8 timer;

    timer              = g_SpadWork->unk_09 + 1;
    g_SpadWork->unk_09 = timer;
    if (timer == 120) {
        g_SpadWork->unk_02 = g_SpadWork->unk_02 + 1;
    }
}

INCLUDE_ASM(func_801EF3C4);

INCLUDE_ASM(func_801EF44C);

INCLUDE_ASM(func_801EFD20);

INCLUDE_ASM(func_801EFDD4);

MATCH void func_801F0008(void) {
    func_8014D290();
    if (func_8014DAEC() & BYTE_MASK) {
        func_801E5988();
    }
}

INCLUDE_ASM(func_801F0044);

INCLUDE_ASM(func_801F009C);

INCLUDE_ASM(func_801F0104);

INCLUDE_ASM(func_801F0158);

INCLUDE_ASM(func_801F01C0);

INCLUDE_ASM(func_801F0224);

INCLUDE_ASM(func_801F0274);

INCLUDE_ASM(func_801F04B0);

INCLUDE_ASM(func_801F078C);

INCLUDE_ASM(func_801F08AC);

INCLUDE_ASM(func_801F0974);

#include "overlays/bmagic/Effect_SetActorMatrix.h"
