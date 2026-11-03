#include "boss001_13.h"

MATCH void func_800C1900(void) {
    EnemyBattler* work;

    func_8014DAEC();
    func_801E54EC();
    work = g_BattleCurrentEnemy;
    work->flags_100 |= 0x1000;
    g_SpadWork[0] &= 0xBF;
    ACTOR_SET_STEP(3);
    g_SpadWork[2] = 0;
    g_SpadWork[3] = 0;
}
