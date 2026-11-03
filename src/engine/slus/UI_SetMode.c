#include "engine/slus/slus.h"

/* stores one frontend-local mode and installs the matching callback.
 */
/* func_8014ECAC */
MATCH void UI_SetMode(u16 local_mode) {
    if (WINDOW_EFFECT_BUSY()) {
        return;
    }
    g_UiLocalMode = local_mode & BYTE_MASK;
    CallbackRegister(2, UI_DispatchLocalMode);
}
