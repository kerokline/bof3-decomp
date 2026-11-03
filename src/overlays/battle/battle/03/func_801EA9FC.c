#include "battle_03.h"

MATCH void func_801EA9FC(void) {
    s16 y;

    y = (s16)g_MenuPanelTaskCurrent->y;
    if (y == -22) {
        D_801EC2E4                    = 0;
        g_MenuPanelTaskCurrent->state = 0;
    } else {
        g_MenuPanelTaskCurrent->y = y - 8;
    }
    func_801D7EB0((s32)(s16)g_MenuPanelTaskCurrent->x, (s32)(s16)g_MenuPanelTaskCurrent->y);
    UI_DrawText((s16)(g_MenuPanelTaskCurrent->x + 4), (s16)(g_MenuPanelTaskCurrent->y + 3), 0, 0xFF,
                D_801EB5B4[((D_801EBF04 - 1) & 0xF) * 2]);
}
