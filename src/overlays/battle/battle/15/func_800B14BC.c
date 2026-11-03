#include "battle_15.h"

MATCH void func_800B14BC(void) {
    s16 current;

    func_800B1728();
    current                   = (s16)g_MenuPanelTaskCurrent->x;
    g_MenuPanelTaskCurrent->x = (u16)(current >= 92 ? current - 32 : 91);
}
