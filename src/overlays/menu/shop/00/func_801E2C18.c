#include "shop_00.h"

MATCH void func_801E2C18(void) {
    D_801E5DDC[g_MenuPanelTaskCurrent->state]();
    /* FAKE: retail reads g_CharSlot as u8[]. */
    Menu_DrawEquipStatWindow(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y,
                             ((u8*)g_CharSlot)[D_80144F5A[g_MenuPanelTaskCurrent->unk_0A]],
                             g_MenuPanelTaskCurrent->unk_0B, g_MenuPanelTaskCurrent->unk_0C);
}
