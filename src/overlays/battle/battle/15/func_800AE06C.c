#include "battle_15.h"

/* Stores 60 in byte 9 and increments byte 1 of the scratchpad buffer at slots[0x11]. */
MATCH void func_800AE06C(void) {
    void** slots;
    void*  sp_ptr;

    slots            = SP_PTR(void*, 0u);
    sp_ptr           = slots[0x11];
    ((u8*)sp_ptr)[9] = 0x3C;
    sp_ptr           = slots[0x11];
    ((u8*)sp_ptr)[1]++;
}
