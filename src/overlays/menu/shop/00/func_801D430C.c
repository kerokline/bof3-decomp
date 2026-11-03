#include "shop_00.h"

MATCH void func_801D430C(void) {
    u8* counter;

    if (WINDOW_EFFECT_IDLE()) {
        func_801D6E94();
        counter = &D_80148652;
        *counter += 1;
    } else if (D_8014865C != -1) {
        Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
        WinDrawCueText(28, 22, 0xA4);
    }
}
