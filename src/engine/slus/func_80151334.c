#include "engine/slus/slus.h"

/* clears g_UiWindowStep and toggles bit 2 of g_UiWindowChannel when D_80148333 is 2.
 */
MATCH void func_80151334(void) {
    if (D_80148333[0] == 2) {
        g_UiWindowStep = 0;
        g_UiWindowChannel ^= FRONTEND_FLAG_SELECTION;
    }
}
