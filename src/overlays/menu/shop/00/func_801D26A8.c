#include "shop_00.h"

MATCH void func_801D26A8(void) {
    u8* block;
    u8  i;
    u8* state;

    block = Item_GetRecord(D_801E6048, D_801E604C);
    TEXT_SetVariable(0, 0xC, block);
    D_80148340 = 0x4D;
    D_80148624 = 0;
    if (g_InputPressed != 0) {
        i = 0;
        while ((u8)i < (u8)Party_CountOrder(0)) {
            if (i == LOB(D_80148656)) {
                D_80148333[((i + 3) * 9) << 2] = 4;
            } else {
                D_80148333[((i + 3) * 9) << 2] = 2;
            }
            i++;
        }
        D_8014840B = 1;
        if ((Party_CountItem(D_801E6048, D_801E604C, 0) & HALF_MASK) != 0) {
            state = &D_80148652;
            *state -= 2;
        } else {
            state = &D_80148652;
            *state -= 6;
        }
    }
}
