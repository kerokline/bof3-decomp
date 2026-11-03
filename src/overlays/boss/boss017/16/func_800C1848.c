#include "boss017_16.h"

MATCH void func_800C1848(void) {
    EnemyBattler* work;

    work         = g_BattleCurrentEnemy;
    /* FAKE: retail reads D_800C1A70 as u8[]. */
    work->script = ((u8*)&D_800C1A70);
    work->unk_E4 = func_800C1964;
    work->unk_E8 = D_800C1A94;
    ACTOR_SET_STEP(2);
    func_8014D978();
}
