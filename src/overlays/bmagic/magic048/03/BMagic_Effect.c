#include "magic048_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC70);

INCLUDE_ASM(func_801EEDB0);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEE70(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEEB4);

INCLUDE_ASM(func_801EEF3C);

INCLUDE_ASM(func_801EF05C);

INCLUDE_ASM(func_801EF158);

INCLUDE_ASM(func_801EF234);

INCLUDE_ASM(func_801EF5C8);

INCLUDE_ASM(func_801EF6A0);
