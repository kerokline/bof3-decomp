#include "area175_13.h"

MATCH void func_801F3998(void) {
    if (MENU_SELECTION_IDLE()) {
        MESSAGE_REQUEST_CLEAR();
        D_801F294D = 0;
    } else {
        g_MessageRequest = 0x5F;
        D_801F294C++;
    }
}
