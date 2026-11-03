#include "battle_03.h"

MATCH void func_801D2FC0(void) {
    if (g_BattleEncounter != 0) {
        g_BossBattleEventHook(1);
    }
    g_BattleStep    = 1;
    g_BattleSubStep = g_BattleActionType;
}
