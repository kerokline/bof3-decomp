#include "boss002_16.h"

MATCH void func_800C1A4C(void) {
    EnemyBattler* work;
    u8*           flags;
    u32           limit;
    s32           remaining;

    work      = g_BattleCurrentEnemy;
    remaining = work->hp_94 - work->damage_F8;
    limit     = work->cell_A0.max_hp >> 2;
    if (!((s32)limit < remaining)) {
        flags = &g_BattleBossFlags;
        *flags |= 1;
        work->hp_94 = 0xFFFF;
    }
}
