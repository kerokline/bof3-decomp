#include "magic102_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/func_801EEC14.h"

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
