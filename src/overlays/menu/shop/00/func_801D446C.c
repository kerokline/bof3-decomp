#include "shop_00.h"

MATCH void func_801D446C(void) {
    s16 i;

    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    if (WINDOW_EFFECT_IDLE()) {
        func_801D68D0(1);
        D_8014865B           = 1;
        D_80148652           = D_80148652 + 1;
        g_InputRepeatButtons = 0;
        g_InputRepeatDelay   = 0;
        if (D_8014865C != -1) {
            Resource_RequestArea(0xD5);
        }
        for (i = 0; i < 4; i++) {
            if (D_801E6100[i] != 0) {
                SsSepReplay(0, i);
            }
        }
    }
}
