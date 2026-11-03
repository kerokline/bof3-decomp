#include "area192_13.h"

MATCH void func_801F2DBC(void) {
    MESSAGE_REQUEST_CLEAR();
    if (D_801490C7 == 1) {
        Game_SetScriptActive();
        D_801448EB = 0x36;
        D_801448EC = 0x1E;
    } else if (D_801490C7 == 2) {
        Game_SetScriptActive();
        g_SceneState.state_04 = 1;
        g_SceneState.step_05  = 0x14;
    }
}
