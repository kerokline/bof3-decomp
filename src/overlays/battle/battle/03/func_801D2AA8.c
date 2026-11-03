#include "battle_03.h"

MATCH void func_801D2AA8(void) {
    D_801EAC10[g_BattleStep]();
    if ((g_InputHeld & D_80145AC4) != 0u) {
        g_BattleState &= ~BATTLE_STATE_COMMAND_ARMED;
    }
}
