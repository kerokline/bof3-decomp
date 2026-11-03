#include "shop_00.h"

MATCH void func_801D1D60(void) {
    s32  stock;
    s8*  toggle;
    u16* pad;

    TEXT_SetVariable(0, 12, Item_GetRecord(D_801E6048, D_801E604C));
    toggle     = &D_8014865B;
    pad        = &g_InputPressed;
    D_80148340 = 0x49;
    D_80148624 = 1;
    D_80148628 = (u16)D_80148334 + ((1 - *toggle) * 32) + 0xDE;
    D_8014862A = (u16)D_80148336 + 5;
    if (*pad & (PADLright | PADLleft)) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
        *toggle ^= 1;
    }
    if (*pad & D_80145AC2) {
        if (*toggle != 0) {
            u32* zenny;

            SND_PlayCue(EMI_CUE_ID(1, 4));
            zenny = &g_Zenny;
            *zenny -= D_801E6060 * D_801E6050;
            Party_AddItem(D_801E6048, D_801E604C, D_801E6050, 0);
            stock = Item_GetKind(D_801E6048, D_801E604C);
            if (D_801E6058 != 0 && D_801E6048 != 0 && ((u32)((stock - 0xA) & BYTE_MASK) >= 2)) {
                *toggle    = 1;
                D_80148652 = D_80148652 + 1;
            } else {
                u8* mode;

                mode  = &D_80148652;
                *mode = *mode - 2;
            }
            return;
        }
        SND_PlayCue(EMI_CUE_ID(1, 6));
        D_80148652 -= 2;
        return;
    }
    if (*pad & D_80145AC4) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        D_80148652 -= 2;
    }
}
