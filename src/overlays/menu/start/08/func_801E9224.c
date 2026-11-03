#include "start_08.h"

MATCH void func_801E9224(void) {
    D_801ED3BC[g_MenuPanelTaskCurrent->state]();
    Menu_DrawPlayTimeWindow(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y);
}
