#include "area175_13.h"

MATCH void func_801F3DDC(void) {
    if (MENU_SELECTION_IDLE()) {
        MESSAGE_REQUEST_CLEAR();
        D_801F294C = 0;
    } else {
        g_MessageRequest = 0xF7;
        D_801F294C       = 4;
    }
}
