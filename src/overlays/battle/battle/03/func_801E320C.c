#include "battle_03.h"

MATCH void func_801E320C(void) {
    *(u32*)((u32)g_BattleCurrentEnemy + 0xECu) = (u32)(g_BattleEnemies - 0x60);
    g_BattleChooseEndingHook                   = func_801E5768;
    g_BattleEndHook                            = func_801E57C8;
    func_801E2314(0);
    g_SpadWork->flags_00 |= ACTOR_FLAG_HIDDEN;
    func_801DDAB4(g_BattleCurrentEnemy->status_82);
    g_SpadWork->step_01 += 1;
}
