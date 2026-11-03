#include "shop_00.h"

MATCH void func_801E29C8(void) {
    D_801E5DC0[g_MenuPanelTaskCurrent->state]();
    Menu_DrawCommandRow((s16)g_MenuPanelTaskCurrent->x, (s16)g_MenuPanelTaskCurrent->y, g_MenuPanelTaskCurrent->unk_0A,
                        g_MenuPanelTaskCurrent->unk_0B, 0);
}
