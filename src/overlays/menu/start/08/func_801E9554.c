#include "start_08.h"

MATCH void func_801E9554(void) {
    u8* resource;
    s32 panel_x;
    u32 label_dx;

    D_801ED3D4[g_MenuPanelTaskCurrent->state]();
    Menu_DrawHeaderBar(g_MenuPanelTaskCurrent->x, g_MenuPanelTaskCurrent->y, 0x48, 0x13, D_80144952);
    resource = Resource_GetText(FIELD(u16, g_MenuPanelTaskCurrent, 0x10));
    label_dx = (func_801AF20C(resource) & BYTE_MASK) * 4 - 0x25;
    panel_x  = (s16)(g_MenuPanelTaskCurrent->x - label_dx);
    UI_DrawText(panel_x, g_MenuPanelTaskCurrent->y + 3, 0, func_801AF20C(resource) & BYTE_MASK, resource);
}
