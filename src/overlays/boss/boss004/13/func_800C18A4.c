#include "boss004_13.h"

MATCH void func_800C18A4(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C2720;
    work->unk_E4 = func_800C1BBC;
    work->unk_E8 = D_800C2738;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
