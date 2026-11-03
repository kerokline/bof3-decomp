#include "area135_14.h"

MATCH void func_801F3ED8(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_801448EB = 0x12;
        D_801448EC = 0;
    }
}
