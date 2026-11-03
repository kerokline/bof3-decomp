#include "area135_14.h"

MATCH void func_801F4888(void) {
    if (g_GameStateIndex == 5) {
        func_801F5F28();
    } else {
        g_ScriptState->cursor = (u16)(g_ScriptState->cursor - 2);
    }
}
