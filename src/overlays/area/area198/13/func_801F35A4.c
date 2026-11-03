#include "area198_13.h"

MATCH void func_801F35A4(void) {
    if (g_GameStateIndex == GAME_REQUEST_AREA_CHANGE) {
        GFX_FreePaletteSlotOwner((s32)SP_REF(void*, 0x44u));
    } else {
        g_ScriptState->cursor = (u16)(g_ScriptState->cursor - 2u);
    }
}
