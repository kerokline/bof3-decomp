#include "shop_00.h"

MATCH void func_801D46E0(void) {
    u8* counter;
    u8  count;

    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    counter  = &D_80148652;
    count    = *counter;
    *counter = count + 1;
}
