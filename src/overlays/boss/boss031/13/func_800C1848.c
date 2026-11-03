#include "boss031_13.h"

MATCH void func_800C1848(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1AB8;
    work->unk_E4 = func_800C1978;
    work->unk_E8 = D_800C1AC4;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
