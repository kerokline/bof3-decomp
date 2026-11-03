#include "area192_13.h"

MATCH void func_801F2CA8(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_IDLE()) {
        Game_SetScriptActive();
        g_SceneState.state_04 = 1;
        g_SceneState.step_05  = 0x14;
    }
}
