#include "area136_13.h"

MATCH void func_801F2C94(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        D_801448EB = 0x13;
        D_801448EC = 0;
        D_801448ED = 1;
    }
}
