#include "boss025_13.h"

MATCH void Boss_InstallBattleHooks2(void) {
    g_BattleChooseEndingHook = Boss_ChooseBattleEnding2;
    g_BattleEndHook          = Boss_EndBattle2;
    g_BossBattleEventHook    = Boss_HandleBattleEvent2;
    D_801FE4F0               = 0;
    D_801FE4E8               = 0;
    D_801FE4EF               = 0;
}
