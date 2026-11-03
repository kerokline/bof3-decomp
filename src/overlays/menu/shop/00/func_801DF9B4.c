#include "shop_00.h"

/* File-local declarations: D_801E6260 and func_801E0F78 are not shared with
 * other targets yet, so they stay owned by this translation unit. */

MATCH void func_801DF9B4(void) {
    u8* counter;
    u8  count;

    func_801E0F78();
    counter    = &D_80148651;
    count      = *counter;
    D_801E6260 = 0;
    *counter   = count + 1;
}
