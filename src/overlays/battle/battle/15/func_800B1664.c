#include "battle_15.h"

MATCH void func_800B1664(void) {
    func_800B1728();
    if ((s16)g_MenuPanelTaskCurrent->x >= 0xA4) {
        g_MenuPanelTaskCurrent->x = g_MenuPanelTaskCurrent->x - 32;
    }
    if ((s16)g_MenuPanelTaskCurrent->x < 0xA3) {
        g_MenuPanelTaskCurrent->x = 163;
    }
}
