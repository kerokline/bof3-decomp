#include "magic132_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC18(void) {
    BattleHandlerTable5 handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC88);

INCLUDE_ASM(func_801EEDD0);

INCLUDE_ASM(func_801EEEF4);

#include "overlays/bmagic/Effect_RequestTargetOnTimerZero.h"

INCLUDE_ASM(func_801EF0A4);

MATCH void func_801EF114(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EF158);

INCLUDE_ASM(func_801EF200);

INCLUDE_ASM(func_801EF324);

INCLUDE_ASM(func_801EF388);

INCLUDE_ASM(func_801EF3E0);

INCLUDE_ASM(func_801EF44C);

INCLUDE_ASM(func_801EF4A4);

INCLUDE_ASM(func_801EF5B0);

INCLUDE_ASM(func_801EF914);
