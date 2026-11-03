#include "battle_03.h"

MATCH void func_801EAAB8(void) {
    func_801D7EB0((s16)g_MenuPanelTaskCurrent->x, (s16)g_MenuPanelTaskCurrent->y);
    UI_DrawText((s16)(g_MenuPanelTaskCurrent->x + 4u), (s16)(g_MenuPanelTaskCurrent->y + 3u), 0, 0xFFu,
                (u8*)(D_801EB5B4[D_801EBF04 * 2]));
}
