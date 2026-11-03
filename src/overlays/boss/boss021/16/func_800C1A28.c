#include "boss021_16.h"

MATCH void func_800C1A28(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1CBC;
    work->unk_E4 = func_800C1A80;
    work->unk_E8 = D_800C1CD0;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
