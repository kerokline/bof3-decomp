#include "area175_13.h"

MATCH void func_801F386C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        D_80146875 = 2;
    } else {
        D_80146875 = 3;
    }
}
