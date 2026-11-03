#include "shop_00.h"

/* File-local declarations: the panel handler table selected by panel-task
 * byte 3 and the shop draw helper are owned by this overlay. */

MATCH void func_801E3E4C(void) {
    D_801E5E70[g_MenuPanelTaskCurrent->state]();
    Menu_DrawCharacterWindow(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, g_MenuPanelTaskCurrent->unk_0A, 0,
                             0);
}
