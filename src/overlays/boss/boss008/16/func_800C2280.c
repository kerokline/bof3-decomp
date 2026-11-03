#include "boss008_16.h"

MATCH void func_800C2280(void) {
    g_BattleChooseEndingHook = Boss_ChooseBattleEnding4;
    g_BattleEndHook          = Boss_EndBattle4;
    g_BossBattleEventHook    = Boss_HandleBattleEvent4;
}
