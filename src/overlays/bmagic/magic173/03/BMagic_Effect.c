#include "magic173_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback handlers[2] = {func_801EEC5C, func_801EED90};

    SYS_DISPATCH_TASK(handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC5C);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEDF0(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEE34);

INCLUDE_ASM(func_801EEEEC);

INCLUDE_ASM(func_801EF148);

INCLUDE_ASM(func_801EF3D8);

INCLUDE_ASM(func_801EF484);

INCLUDE_ASM(func_801EF4EC);

INCLUDE_ASM(func_801EFA34);

INCLUDE_ASM(func_801F02B0);

INCLUDE_ASM(func_801F03A0);

INCLUDE_ASM(func_801F0488);

INCLUDE_ASM(func_801F0540);

INCLUDE_ASM(func_801F0648);

INCLUDE_ASM(func_801F06B0);

INCLUDE_ASM(func_801F0700);

INCLUDE_ASM(func_801F075C);
