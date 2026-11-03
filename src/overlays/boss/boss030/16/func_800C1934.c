#include "boss030_16.h"

MATCH void func_800C1934(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1AC0;
    work->unk_E4 = func_800C198C;
    work->unk_E8 = D_800C1AD4;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
