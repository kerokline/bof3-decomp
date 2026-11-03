#include "shop_00.h"

MATCH void func_801E20CC(void) {
    volatile u8* timer;
    u8           temp;
    u8           count;

    timer  = &D_80148654;
    temp   = *timer - 1;
    *timer = temp;
    if (temp == 0) {
        count      = D_80148651;
        D_80148652 = 0;
        D_80148651 = count + 1;
    }
}
