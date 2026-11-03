#include "area111_13.h"

MATCH void func_801F33F8(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_80146874 = 5;
        D_80146875 = 0;
    }
}
