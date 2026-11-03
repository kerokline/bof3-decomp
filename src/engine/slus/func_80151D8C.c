#include "engine/slus/slus.h"

/* shifts D_801490C8 left by four, copies D_801490AA into D_801490CA
 * and bumps D_801490A3.
 */
MATCH void func_80151D8C(void) {
    u16* counter;
    u16  value;
    u8   next;

    counter    = (u16*)&D_801490C8;
    next       = D_801490A3 + 1;
    value      = *counter << 4;
    *counter   = value;
    D_801490CA = D_801490AA;
    D_801490A3 = next;
}
