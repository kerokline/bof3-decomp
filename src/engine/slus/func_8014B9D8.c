#include "engine/slus/slus.h"

/* clears bit 6 of the callback slot word for slot_index.
 */
MATCH void func_8014B9D8(s32 slot_index) {
    D_80143B40[slot_index].state &= ~0x40;
}
