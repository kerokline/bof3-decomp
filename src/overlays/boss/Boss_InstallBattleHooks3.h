/* Publishes the area entry points Boss_ChooseBattleEnding3, Boss_EndBattle3 and Boss_HandleBattleEvent3 into
 * g_BattleChooseEndingHook, g_BattleEndHook and g_BossBattleEventHook. One definition shared by the boss overlays;
 * each includes this file where the function sits. */
/* func_800C1F08 (boss002), func_800C2184 (boss008), func_800C234C (boss004), func_800C26DC (boss018) */
MATCH void Boss_InstallBattleHooks3(void) {
    g_BattleChooseEndingHook = Boss_ChooseBattleEnding3;
    g_BattleEndHook          = Boss_EndBattle3;
    g_BossBattleEventHook    = Boss_HandleBattleEvent3;
}
