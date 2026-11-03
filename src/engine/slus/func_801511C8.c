#include "engine/slus/slus.h"

/* increments g_UiWindowStep[0] when D_80148357 is 2 and D_80148333 is 4.
 */
MATCH void func_801511C8(void) {
    if ((D_80148357 == 2) && (D_80148333[0] == 4)) {
        /* FAKE: retail addresses g_UiWindowStep as an array element; the scalar spelling folds the address. */
        MEM(u8, (u32)&g_UiWindowStep) += 1;
    }
}
