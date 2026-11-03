#include "magic075_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC70);

INCLUDE_ASM(func_801EEDE0);

INCLUDE_ASM(func_801EEEB0);

MATCH void func_801EEFF4(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF038);

INCLUDE_ASM(func_801EF0D0);

INCLUDE_ASM(func_801EF2A8);

INCLUDE_ASM(func_801EF2F4);

INCLUDE_ASM(func_801EF500);
