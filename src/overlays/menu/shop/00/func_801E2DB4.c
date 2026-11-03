#include "shop_00.h"

MATCH void func_801E2DB4(void) {
    D_801E5DF0[g_MenuPanelTaskCurrent->state]();
    Shop_DrawEquipment((s16)g_MenuPanelTaskCurrent->x, (s16)g_MenuPanelTaskCurrent->y,
                       g_CharSlot[D_80144F5A[g_MenuPanelTaskCurrent->unk_0A]]);
}
