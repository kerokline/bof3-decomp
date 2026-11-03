#include "game_00.h"

MATCH void func_801C1840(void) {
    u8* row;
    u8* cell;
    s32 outer;
    s32 inner;

    outer = 0;
    row   = (u8*)D_801454F4;
loop:
    inner = 2;
    cell  = row + 2;
    do {
        *cell = 0;
        inner -= 1;
        cell -= 1;
    } while (inner >= 0);
    outer += 1;
    row += 3;
    if (outer < 3) {
        goto loop; /* clear the next row */
    }
}
