#include "shop_00.h"

MATCH void func_801DE40C(void) {
    u8* counter;
    u8  count;

    func_801DF6A8();
    if (WINDOW_EFFECT_IDLE()) {
        counter    = &D_80148651;
        count      = *counter;
        D_80148652 = 0;
        *counter   = count + 2;
    }
}
