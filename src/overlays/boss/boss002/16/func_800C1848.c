#include "boss002_16.h"

MATCH void func_800C1848(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1F9C;
    work->unk_E4 = func_800C19C8;
    work->unk_E8 = D_800C1FAC;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
