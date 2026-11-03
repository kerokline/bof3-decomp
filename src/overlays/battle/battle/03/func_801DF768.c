#include "battle_03.h"

MATCH void func_801DF768(void) {
    if ((g_BattleSelectionLatch != 0u) && ((*D_801EB4D8 == g_SpadWork->slot) || ((*D_801EB4D8 & 0x80u) != 0u))) {
        g_SpadWork->unk_07 = (u8)GFX_AllocPaletteFade((u8*)g_SpadWork, 0, 0, 0, 0);
        g_SpadWork->unk_02 = 1u;
    }
}
