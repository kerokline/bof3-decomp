#include "shop_00.h"

MATCH void func_801E4DF4(MenuPanelTask* panel_task) {
    u8* bytes;

    bytes = (u8*)panel_task;
    UI_DrawWindow((s32)(u16)(panel_task->x + 3), (s32)(u16)(panel_task->y + 3), 154, 57, 0, (s32)D_80144952);
    Menu_DrawPanelFrame((s16)panel_task->x, (s16)panel_task->y, 0x12, 6);
    WinDrawCueText((s16)(panel_task->x + 14), (s16)(panel_task->y + 4), bytes[0xA] | 0x100);
}
