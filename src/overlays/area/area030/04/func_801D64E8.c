#include "area030_04.h"

/* Ticks down the work counter at scratch+9 and dispatches on the
 * new value. */
MATCH void func_801D64E8(void) {
    u8** slots;
    u8*  work;
    u8   count;

    slots = SP_PTR(u8*, 0u);
    work  = slots[0x11];
    work[9] -= 1;
    slots = SP_PTR(u8*, 0u);
    count = slots[0x11][9];
    if (count == 0) {
        Actor_Clear();
        return;
    }
    if (count & 8) {
        Area_AddActor();
    }
}
