#include "game_00.h"

MATCH s32 func_801B57F8(void) {
    u32 mode;

    if (((g_GameFlags | g_AreaWalkFlags) & AREA_WALK_BUSY_ALL) != 0) {
        return 0;
    }
    mode = g_PartySize;
    if (mode <= 1u) {
        goto ret_one; /* one or two slots are open, the gate allows */
    }
    if ((D_80145FD1 != 1) && (D_80145FD1 != 6)) {
        goto ret_one; /* only modes 1 and 6 pass the gate */
    }
    if (mode != 3) {
        goto ret_one; /* any mode but 3 fails the gate */
    }
    if ((D_80146111 == 1) || (D_80146111 == 6)) {
        goto ret_one; /* the held direction pair is not one of 1 and 6 */
    }
    return 0;
ret_one:
    return 1;
}
