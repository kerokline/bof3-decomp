#include "boss028_16.h"

MATCH void func_800C1848(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C2140;
    work->unk_E4 = func_800C1AF0;
    work->unk_E8 = D_800C214C;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
