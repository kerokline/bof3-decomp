#include "battle_03.h"

MATCH void func_801E6BC8(void) {
    u8** scratch_slots;

    if (func_8014D978() != 0u) {
        scratch_slots = SP_PTR(u8*, 0u);
        scratch_slots[0x11][1]++;
        scratch_slots          = SP_PTR(u8*, 0u);
        scratch_slots[0x11][9] = 0x10;
    }
}
