#include "commu00_00.h"

/* The variant stays a byte: the byte width is what keeps the drawn value live
 * across the range check, so retail copies it and re-masks it before the label
 * add; a wider local subtracts in place and adds unmasked. */
MATCH void func_801F0BF4(u8 task_index) {
    u8 variant;

    variant = RANDOM_MASK(0x7);
    if (variant >= 5) {
        variant -= 4;
    }
    g_Actors[task_index].unk_06 = 1;
    g_Actors[task_index].unk_7C = variant + 0xC2;
}
