#include "magic002_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC78);

INCLUDE_ASM(func_801EEDE4);

#include "shared/Effect_StartPlaying.h"

MATCH void func_801EEE64(void) {
    Bmagic_DispatchTaskPair(func_801EEEBC, func_801EEF84);
}

INCLUDE_ASM(func_801EEEBC);

INCLUDE_ASM(func_801EEF84);

INCLUDE_ASM(func_801EF030);

INCLUDE_ASM(func_801EF1FC);
