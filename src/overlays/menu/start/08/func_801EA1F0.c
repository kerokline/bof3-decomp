#include "start_08.h"

MATCH void func_801EA1F0(MenuPanelTask* task) {
    u8  group_index;
    s16 row;
    u8  i;
    u32 color;
    UI_DrawWindow((task->x + 3) & HALF_MASK, (task->y + 3) & HALF_MASK, 101, (D_801ED560[task->unk_0A][0] * 16) + 25, 0,
                  D_80144952);
    UI_DrawText((s16)(task->x + 39), (s16)(task->y + 7), 0, 0xFFU, (u8*)D_801ED534[0]);
    UI_DrawSpriteRun((s16)task->x, (s16)task->y, D_801ED468, 1);
    group_index = task->unk_0A;
    i           = 0;
    if (D_801ED560[group_index][0] != 0) {
        do {
            color = D_801ED534[D_801ED560[group_index][i + 1]];
            if (i == task->unk_0C) {
                row = i * 0x10 + 0x1A;
                UI_DrawText((s16)(task->x + 7), (s16)(task->y + row), 7, 0xFFU, (u8*)color);
                UI_DrawText((s16)(task->x + 7), (s16)(task->y + row - 2), 2, 0xFFU, (u8*)color);
            } else if (i == task->unk_0B) {
                row = i * 0x10 + 0x1A;
                UI_DrawText((s16)(task->x + 7), (s16)(task->y + row), 7, 0xFFU, (u8*)color);
                UI_DrawText((s16)(task->x + 7), (s16)(task->y + row - 2), 0, 0xFFU, (u8*)color);
            } else {
                row = i * 0x10 + 0x1A;
                UI_DrawText((s16)(task->x + 7), (s16)(task->y + row), 0, 0xFFU, (u8*)color);
            }
            UI_DrawSpriteRun((s16)task->x, (s16)(task->y + (i * 2 + 3) * 8), D_801ED48C, 1);
            UI_DrawSpriteRun((s16)task->x, (s16)(task->y + (i * 2 + 4) * 8), D_801ED48C, 1);
            group_index = task->unk_0A;
            i++;
        } while (i < D_801ED560[group_index][0]);
    }
    row = i * 0x10 + 0x18;
    UI_DrawSpriteRun((s16)task->x, (s16)(task->y + row), D_801ED498, 1);
}
