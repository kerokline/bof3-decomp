#include "area170_13.h"

MATCH void func_801F4A4C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        D_801448EC = 0x37;
    } else {
        D_801448EC = 0x34;
    }
}
