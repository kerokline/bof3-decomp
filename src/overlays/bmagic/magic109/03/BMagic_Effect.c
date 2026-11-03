#include "magic109_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC14(void) {
    MagicTaskFuncs handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC80);

INCLUDE_ASM(func_801EEEAC);

INCLUDE_ASM(func_801EEF30);

INCLUDE_ASM(func_801EF008);

INCLUDE_ASM(func_801EF0F8);
