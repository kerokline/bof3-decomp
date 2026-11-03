#include "area030_04.h"

/* Draws the AREA030 panel header row through the shared helper at
 * `0x801D9534`. */
MATCH void func_801D3908(void) {
    func_801D9534(0x14, 0x12, 0x118, 0x13, 0);
}
