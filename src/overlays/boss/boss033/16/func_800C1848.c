#include "boss033_16.h"

MATCH void func_800C1848(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C2744;
    work->unk_E4 = func_800C1CA4;
    work->unk_E8 = D_800C2750;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
