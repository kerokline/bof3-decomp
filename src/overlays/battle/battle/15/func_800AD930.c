#include "battle_15.h"

MATCH void func_800AD930(void) {
    PartyBattler* work;
    u8            flag;

    flag = *MEM_PTR(u8, &g_BattlePanelEntry);
    if (flag != GAME_NONE) {
        work = (PartyBattler*)g_SpadWork;
        work->unk_02--;
    }
    if (!(D_80148624 & 1)) {
        BATTLE_WORK->step_01++;
        BATTLE_WORK->unk_02 = 0;
    }
}
