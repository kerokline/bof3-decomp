#include "area189_13.h"

MATCH void func_801F4CC0(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_801448EB = 0x32;
        D_801448EC = 1;
    }
}
