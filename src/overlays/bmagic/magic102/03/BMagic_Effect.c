#include "magic102_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC14(void) {
    MagicTaskFuncs handlers;

    handlers = D_801EEC04;
    SYS_DISPATCH_TASK(handlers.handlers, 1, g_SpadWork);
}

INCLUDE_ASM(func_801EEC80);

INCLUDE_ASM(func_801EF218);

INCLUDE_ASM(func_801EF2B8);

INCLUDE_ASM(func_801EFD7C);

INCLUDE_ASM(func_801EFEFC);

/* Template: exe Area_DrawGouraudQuads needs the local i, which this function lacks; compile fails. */
INCLUDE_ASM(func_801F016C);

INCLUDE_ASM(func_801F0488);

INCLUDE_ASM(func_801F0778);

INCLUDE_ASM(func_801F0ADC);
