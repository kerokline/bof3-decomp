#include "shop_00.h"

MATCH void func_801D3C9C(void) {
    u8* counter;
    u8  count;

    counter = &D_80148654;
    func_801D6D6C(0x6E - *counter * 48, 0x4C);
    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    if (D_8014865C != -1) {
        WinDrawCueText(28, 22, 0xA1);
        Menu_DrawZennyWindow(0x62, 0x28, 0, g_Zenny);
    }
    count = *counter;
    count--;
    *counter = count;
    if (count == 0) {
        D_80148652 += 1;
    }
}
