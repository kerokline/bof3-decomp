#include "area150_13.h"

MATCH void func_801F2CDC(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        D_801448EC = 0xE;
    } else {
        D_801448EC = 0xC;
    }
}
