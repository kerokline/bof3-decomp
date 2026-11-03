#include "area198_13.h"

MATCH void func_801F39B4(void) {
    GFX_FreePaletteSlotOwner((s32)g_SpadWork);
    GFX_StartPaletteAnimation((u8*)g_SpadWork, D_801F4368);
    g_SpadWork->unk_2A = 1;
    g_SpadWork->flags_00 |= ACTOR_FLAG_SEMI_TRANSPARENT;
    Actor_SelectScript(0);
}
