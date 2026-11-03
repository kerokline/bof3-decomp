#include "boss007_16.h"

MATCH void func_800C1864(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    work->script = D_800C1D78;
    work->unk_E4 = func_800C18BC;
    work->unk_E8 = D_800C1D90;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
