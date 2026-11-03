#include "shop_00.h"

MATCH void func_801D456C(void) {
    s32 confirm;

    Menu_DrawHeaderBar(0x14, 0x12, 0x118, 0x13, D_80144952);
    if (D_8014865C != -1) {
        confirm = g_UiWindowChannel & FRONTEND_FLAG_CONFIRM;
    } else {
        WinDrawCueText(28, 22, 0x1D);
        confirm = Menu_ToggleOption() & BYTE_MASK;
    }
    if (confirm != 0) {
        D_80148652 += 1;
    }
}
