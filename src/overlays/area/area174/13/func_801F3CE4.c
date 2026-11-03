#include "area174_13.h"

MATCH void func_801F3CE4(void) {
    if (g_GameStateIndex == 5u) {
        GFX_FreePaletteSlotOwner((s32)SP_REF(void*, 0x44u));
    } else {
        FIELD(u16, (void*)(u32)g_ScriptState, 0xAu) = (u16)(FIELD(u16, (void*)(u32)g_ScriptState, 0xAu) - 2u);
    }
}
