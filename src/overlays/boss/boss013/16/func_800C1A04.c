#include "boss013_16.h"

MATCH void func_800C1A04(void) {
    EnemyBattler* work;

    work = g_BattleCurrentEnemy;
    if (work->hp_94 == 0) {
        work->hp_94 = 1;
    }
}
