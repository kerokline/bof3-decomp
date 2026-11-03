#include "shop_00.h"

MATCH void func_801E0028(void) {
    volatile u8* p   = &D_80148654;
    u8           val = *p - 1;
    *p               = val;
    if (val == 0) {
        D_80148652 += 1;
    }
}
