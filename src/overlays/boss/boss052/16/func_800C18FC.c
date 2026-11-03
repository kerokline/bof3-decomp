#include "boss052_16.h"

MATCH void func_800C18FC(void) {
    Actor_RequestScript(3);
    func_8014DAEC();
    func_801E54EC();
    g_BattleCurrentEnemy->flags_100 |= COMBATANT_FLAG_SKIP_ACTION_STEP;
    g_SpadWork[0] &= ~ACTOR_FLAG_HIDDEN;
    ACTOR_SET_STEP(3);
    g_SpadWork[2] = 0;
    g_SpadWork[3] = 0;
}
