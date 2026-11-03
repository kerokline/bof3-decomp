#include "shop_00.h"

MATCH void func_801E2AB0(void) {
    D_801E5DCC[g_MenuPanelTaskCurrent->state]();
    Menu_DrawZennyWindow(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, 0, g_Zenny);
}
