#include "commu05_07.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

/* The overlay entry: the commu state byte selects the step handler. */
MATCH void func_801D0C10(void) {
    SYS_DISPATCH_BYTE(D_801D1950, D_801F294C);
}

INCLUDE_ASM(func_801D0C4C);

INCLUDE_ASM(func_801D0D4C);

MATCH void func_801D0F34(void) {
    /* FAKE: retail reads D_801448EC as u8[]. */
    ((u8*)&D_801448EC)[0] += 1;
}

INCLUDE_ASM(func_801D0F50);

INCLUDE_ASM(func_801D1048);

INCLUDE_ASM(func_801D129C);

INCLUDE_ASM(func_801D14C8);

INCLUDE_ASM(func_801D1670);

INCLUDE_ASM(func_801D1724);
