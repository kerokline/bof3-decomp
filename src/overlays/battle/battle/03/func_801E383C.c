#include "battle_03.h"

MATCH void func_801E383C(void) {
    u8 value;

    if (g_BattleSelectionLatch != 0) {
        value = *D_801EB4D8;
        if ((value == g_SpadWork->slot) || (value & BATTLE_TARGET_ENEMY_SIDE)) {
            g_SpadWork->unk_07 = (u8)GFX_AllocPaletteFade((u8*)g_SpadWork, 0, 0, 0, 0);
            g_SpadWork->unk_02 = 1;
        }
    }
}
