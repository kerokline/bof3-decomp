#include "boss021_16.h"

MATCH void func_800C1860(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1CB0;
    work->unk_E4 = func_800C198C;
    work->unk_E8 = D_800C1CC8;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
