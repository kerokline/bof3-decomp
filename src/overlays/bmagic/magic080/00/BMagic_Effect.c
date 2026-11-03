#include "magic080_00.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback table[2] = {func_801EEC5C, func_801EECE4};

    table[SP_REF(u8*, 0x44)[1]]();
}

INCLUDE_ASM(func_801EEC5C);

INCLUDE_ASM(func_801EECE4);

INCLUDE_ASM(func_801EED94);

INCLUDE_ASM(func_801EEF5C);
