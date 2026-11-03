#include "boss014_16.h"

MATCH void func_800C1934(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1B28;
    work->unk_E4 = func_800C1998;
    work->flags_104 |= COMBATANT_FLAG_MODE_HANDLER_ACTION;
    work->unk_E8 = D_800C1B3C;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
