#include "area175_13.h"

MATCH void func_801F3D60(void) {
    if (MENU_SELECTION_ARMED()) {
        D_801F294C = 2;
    } else {
        D_801F294C = 1;
    }
    g_MessageRequest = 0xEF;
}
