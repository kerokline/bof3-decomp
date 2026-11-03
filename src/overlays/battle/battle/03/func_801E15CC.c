#include "battle_03.h"

MATCH void func_801E15CC(void) {
    func_801DEDE4();
    if (HAS_STATUS(*g_GameState, STATUS_KO)) {
        g_SpadWork->step_01 = 6;
        g_SpadWork->unk_02  = 4;
    } else {
        Battle_ClearSlotPending(g_SpadWork->slot);
        g_SpadWork->step_01 = 3;
        g_SpadWork->unk_02  = 0;
    }
    g_SpadWork->unk_03 = 0;
}
