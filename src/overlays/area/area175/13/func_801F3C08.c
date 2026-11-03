#include "area175_13.h"

MATCH void func_801F3C08(void) {
    if (MENU_SELECTION_IDLE()) {
        g_MessageRequest = 0x89;
    } else {
        g_MessageRequest = 0x88;
        D_801F294C       = 2;
    }
}
