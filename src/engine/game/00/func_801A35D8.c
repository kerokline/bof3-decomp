#include "game_00.h"

MATCH void func_801A35D8(void) {
    g_CurrentActor->unk_93 = (s8)GFX_AllocPaletteFade((u8*)g_SpadWork, 0x1F, 0x1F, 0x1F, 1);
    g_SpadWork->flags_00 &= ~ACTOR_FLAG_HIDDEN;
    g_SpadWork->unk_04 = 1;
}
