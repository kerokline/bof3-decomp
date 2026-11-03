#include "shop_00.h"

MATCH void func_801E0968(void) {
    u8* delay_ptr;
    u8  count;

    delay_ptr = &D_80148654;
    if (TIMER_EXPIRED(*delay_ptr)) {
        D_801483E5 = 7;
        D_801483E6 = 0xE;
        D_801483E4 = 1;
        D_801483EF = 0xFF;
        D_801483E8 = 0xC8;
        D_801483EE = 0;
        D_801483EA = 0x3F;
        count      = D_80148652;
        D_80148652 = count + 1;
    }
}
