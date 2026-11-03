#include "start_08.h"

/* Panel handler table selected by the shared panel task's state byte; draw
 * helper owned by this overlay. */

MATCH void func_801E9140(void) {
    D_801ED3B0[g_MenuPanelTaskCurrent->state]();
    Menu_DrawZennyWindow(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, 0, g_Zenny);
}
