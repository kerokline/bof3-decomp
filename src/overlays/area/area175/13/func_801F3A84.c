#include "area175_13.h"

MATCH void func_801F3A84(void) {
    if (MENU_SELECTION_IDLE()) {
        MESSAGE_REQUEST_CLEAR();
    } else {
        g_MessageRequest = 0x77;
        D_801F294D       = 0xA;
    }
}
