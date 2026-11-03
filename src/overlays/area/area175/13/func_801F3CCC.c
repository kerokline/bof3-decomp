#include "area175_13.h"

MATCH void func_801F3CCC(void) {
    if (MENU_SELECTION_IDLE()) {
        g_MessageRequest = 0x78;
        D_801F294D       = 0xB;
    } else {
        g_MessageRequest = 0x72;
        D_801F294D       = 0xC;
    }
    D_801F294E = 0;
}
