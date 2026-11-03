#include "engine/slus/slus.h"

/* sets bit 3 of g_UiWindowChannel and, when no request is pending, arms
 * D_801490AA and bumps D_801490A3.
 */
MATCH void func_80151B08(void) {
    u16* counter = (u16*)&g_UiWindowChannel;

    *counter |= FRONTEND_FLAG_REQUEST_PENDING;
    if (D_801490AA == 0) {
        D_801490AA = 1;
        D_801490A3 = D_801490A3 + 1;
    }
}
