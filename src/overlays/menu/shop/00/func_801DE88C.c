#include "shop_00.h"

MATCH void func_801DE88C(void) {
    u8 count;

    if (WINDOW_EFFECT_IDLE()) {
        func_801DF90C();
        count      = D_80148652;
        D_80148654 = 2;
        D_80148652 = count + 1;
    } else {
        func_801DF6A8();
    }
}
