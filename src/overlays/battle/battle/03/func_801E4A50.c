#include "battle_03.h"

MATCH void func_801E4A50(void) {
    if ((g_BattleCurrentEnemy->status_82 & STATUS_KO) != 0u) {
        g_SpadWork->step_01 = 6;
        g_SpadWork->unk_02  = 4;
    } else {
        Battle_ClearSlotPending(g_SpadWork->slot);
        g_SpadWork->step_01 = 2;
        g_SpadWork->unk_02  = 0;
    }
    g_SpadWork->unk_03 = 0;
}
