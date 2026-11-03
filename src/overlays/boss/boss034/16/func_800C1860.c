#include "boss034_16.h"

MATCH void func_800C1860(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C26B8;
    work->unk_E4 = func_800C1D60;
    work->unk_E8 = D_800C26C4;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
