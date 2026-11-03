#include "engine/slus/slus.h"

/* sets bit 1 of g_UiWindowChannel when D_80148333 is 4.
 */
MATCH void func_80150F08(void) {
    if (D_80148333[0] == 4) {
        volatile u16* h = &g_UiWindowChannel;
        *h |= FRONTEND_FLAG_CONFIRM;
    }
}
