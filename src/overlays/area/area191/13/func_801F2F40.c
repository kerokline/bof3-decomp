#include "area191_13.h"

MATCH void func_801F2F40(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_80146874 = 1;
        D_80146875 = 0x14;
    }
}
