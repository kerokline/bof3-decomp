#include "battle_03.h"

MATCH void func_801D2480(void) {
    u8 value;

    value = g_BattlePanelWidths[g_BattlePanelSlot];
    if (value < 8u) {
        g_BattlePanelWidths[g_BattlePanelSlot] = value + 4;
    } else {
        g_BattleStep    = 2;
        g_BattleSubStep = 0;
    }
}
