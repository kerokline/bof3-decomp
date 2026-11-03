#include "shop_00.h"

MATCH void func_801D4614(void) {
    u8 count;

    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    if (D_8014865B == 0) {
        count      = D_80148651;
        D_80148654 = 0;
        D_80148652 = 0;
        D_80148651 = count + 2;
    } else {
        count      = D_80148651;
        D_80148654 = 0;
        D_80148652 = 0;
        D_80148651 = count + 1;
    }
}
