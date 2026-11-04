#include "boss031_13.h"

MATCH void func_800C18E4(void) {
    EnemyBattler* work;

    Actor_RequestScript(1);
    ((Actor*)g_SpadWork)->unk_2A = 1;
    func_8014DAEC();
    func_801E54EC();
    work = g_BattleCurrentEnemy;
    work->flags_100 |= COMBATANT_FLAG_SKIP_ACTION_STEP;
    g_SpadWork[0] &= ~ACTOR_FLAG_HIDDEN;
    ACTOR_SET_STEP(3);
    g_SpadWork[2] = 0;
    g_SpadWork[3] = 0;
}
