#include "battle_03.h"

MATCH void func_801D67EC(void) {
    u8 count = g_BattleSubStep;

    g_MenuPanelMode   = 0;
    g_BattleRowCursor = 0;
    g_BattleSubStep   = count + 1;
}
