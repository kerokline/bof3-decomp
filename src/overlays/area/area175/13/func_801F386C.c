#include "area175_13.h"

MATCH void func_801F386C(void) {
    MESSAGE_REQUEST_CLEAR();
    if (MENU_SELECTION_ARMED()) {
        g_SceneState.step_05 = 2;
    } else {
        g_SceneState.step_05 = 3;
    }
}
