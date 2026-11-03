#include "game_00.h"

MATCH void func_8019986C(void) {
    s16 value;
    u32 color;

    g_MenuTaskHandlers[g_MenuPanelTaskCurrent->state]();
    func_801D50E8(FIELD(s16, g_MenuPanelTaskCurrent, 4u), FIELD(s16, g_MenuPanelTaskCurrent, 6u),
                  (s16)g_MenuPanelTaskCurrent->unk_12, 0x13, (s32)GAME_WINDOW_STYLE);
    value = (s16)g_MenuPanelTaskCurrent->unk_10;
    if (value != 0) {
        color = Resource_Resolve((u32)(u16)value);
        UI_DrawText((s16)(g_MenuPanelTaskCurrent->x + 7), (s16)(g_MenuPanelTaskCurrent->y + 3), 0, 0xFF, (u8*)color);
    }
}
