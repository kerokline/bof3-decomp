#include "battle_15.h"

MATCH void func_800B0A54(void) {
    s16 value;

    value                     = (s16)g_MenuPanelTaskCurrent->y;
    g_MenuPanelTaskCurrent->y = (u16)(value < 0x29 ? value + 16 : 41);
    func_800B0B0C((s16)g_MenuPanelTaskCurrent->x, (s16)g_MenuPanelTaskCurrent->y);
}
