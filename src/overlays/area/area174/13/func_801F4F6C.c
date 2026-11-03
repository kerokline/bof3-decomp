#include "area174_13.h"

MATCH void func_801F4F6C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        D_80146875 = 0x1E;
    } else {
        D_80146875 = 0xA;
    }
}
