#include "magic106_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

INCLUDE_ASM(func_801EEC04);

INCLUDE_ASM(func_801EECE4);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEEE0(void) {
    u8* work;

    work = D_801F05F8;
    D_801EF9C0[work[1]]();
}

INCLUDE_ASM(func_801EEF24);

INCLUDE_ASM(func_801EEFAC);

INCLUDE_ASM(func_801EF16C);

INCLUDE_ASM(func_801EF29C);

INCLUDE_ASM(func_801EF418);

/* Follows BMAGIC_PROJECT_ACTOR_MATRIX (bmagic.h) with the rotation computed from the work
 * halfword at +0x0E and the byte at +0x03; the pointer is a second global. */
INCLUDE_ASM(func_801EF52C);

INCLUDE_ASM(func_801EF5F4);

INCLUDE_ASM(func_801EF914);

MATCH void func_801EF970(void) {
    D_801F05F8[0] = 0;
    D_801F05F8[1] = 0;
    D_801F05F8[2] = 0;
    D_801F05F8[3] = 0;
    D_801F05F8[4] = 0;
}
