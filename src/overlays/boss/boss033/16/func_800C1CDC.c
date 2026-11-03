#include "boss033_16.h"

MATCH void func_800C1CDC(void) {
    if (g_BattleCurrentEnemy->hp_94 == 0xFFFF) {
        g_BattleActionType = 3;
        g_SpadWork[4]      = 0;
    }
}
