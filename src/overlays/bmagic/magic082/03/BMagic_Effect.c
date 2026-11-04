#include "magic082_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/func_801EEC1C.h"

INCLUDE_ASM(func_801EEC94);

INCLUDE_ASM(func_801EEF0C);

INCLUDE_ASM(func_801EEFB4);

#include "overlays/bmagic/Effect_NextStep.h"

INCLUDE_ASM(func_801EF10C);

#include "overlays/bmagic/Effect_StartOnZeroTick.h"

INCLUDE_ASM(func_801EF3A0);

#include "overlays/bmagic/Effect_SetActorMatrix.h"

MATCH void func_801EF56C(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

MATCH void func_801EF5B0(void) {
    SYS_DISPATCH_BYTE(D_801F0D1C, g_SpadWork->unk_02);
    if (g_SpadWork->flags_00 != 0) {
        Effect_SetActorMatrix();
        func_801EFA00();
        func_801EF720();
        PopMatrix();
    }
}

#include "overlays/bmagic/Effect_CountUpAndStep.h"

#include "overlays/bmagic/Effect_StepWhileTickUnderThree.h"

#include "overlays/bmagic/Effect_TickOnTimerZero.h"

INCLUDE_ASM(func_801EF720);

INCLUDE_ASM(func_801EFA00);

MATCH void func_801EFD30(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectFuncs + 5), 2, g_SpadWork);
}

#include "overlays/bmagic/Effect_CountDownAndStep.h"

INCLUDE_ASM(func_801EFDC0);

INCLUDE_ASM(func_801EFEF4);

INCLUDE_ASM(func_801EFFE8);

INCLUDE_ASM(func_801F00DC);

INCLUDE_ASM(func_801F0260);

INCLUDE_ASM(func_801F03E0);

INCLUDE_ASM(func_801F0A84);
