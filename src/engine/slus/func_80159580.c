#include "engine/slus/slus.h"

/* advances the panel's two 12.4 axes by half their per-frame steps
 * and, when an axis reaches zero, snaps that axis to the mode-keyed table
 * value; completing both axes steps the panel state, otherwise the box is
 * redrawn through func_80159FA0.
 */
MATCH void func_80159580(void) {
    MenuPanelTask* task;
    s32            count;

    count        = 0;
    task         = (MenuPanelTask*)g_MenuPanelTaskCurrent;
    task->unk_10 = (u16)(task->unk_10 - task->unk_14);
    task->x      = (u16)(task->x + (s16)task->unk_14 / 2);
    if ((task->unk_10 << 0x10) < 0) {
        switch (task->unk_00[2]) {
            case 0:
                if (task->flags & 2) {
                    task->x = (u16)((g_MenuPanelOrigins[16 + D_801490CE * 2] + (task->unk_0A >> 1)) << 4);
                } else {
                    task->x = (u16)((g_MenuPanelOrigins[D_801490CE * 2] + (task->unk_0A >> 1)) << 4);
                }
                break;
            case 1:
                task->x = (u16)((D_8017F930[D_801490BC.panel_index * 4] + (task->unk_0A >> 1)) << 4);
                break;
            default:
                g_MenuPanelTaskCurrent->x =
                    (u16)((D_8017F944[D_801490CE][0] + (g_MenuPanelTaskCurrent->unk_0A >> 1)) << 4);
                break;
        }
        count++;
        g_MenuPanelTaskCurrent->unk_10 = 0;
    }
    task         = (MenuPanelTask*)g_MenuPanelTaskCurrent;
    task->unk_12 = (u16)(task->unk_12 - task->unk_16);
    task->y      = (u16)(task->y + (s16)task->unk_16 / 2);
    if ((task->unk_12 << 0x10) < 0) {
        switch (task->unk_00[2]) {
            case 0:
                if (task->flags & 2) {
                    task->y = (u16)((g_MenuPanelOrigins[17 + D_801490CE * 2] + (task->unk_0B >> 1)) << 4);
                } else {
                    task->y = (u16)((g_MenuPanelOrigins[1 + D_801490CE * 2] + (task->unk_0B >> 1)) << 4);
                }
                break;
            case 1:
                task->y = (u16)((D_8017F930[1 + D_801490BC.panel_index * 4] + (task->unk_0B >> 1)) << 4);
                break;
            default:
                g_MenuPanelTaskCurrent->y =
                    (u16)((D_8017F944[D_801490CE][1] + (g_MenuPanelTaskCurrent->unk_0B >> 1)) << 4);
                break;
        }
        count++;
        g_MenuPanelTaskCurrent->unk_12 = 0;
    }
    if ((count & BYTE_MASK) == 2) {
        g_MenuPanelTaskCurrent->state++;
        return;
    }
    if (!(g_MenuPanelTaskCurrent->flags & 1)) {
        func_80159FA0((s16)g_MenuPanelTaskCurrent->x >> 4, (s16)g_MenuPanelTaskCurrent->y >> 4,
                      (u8)(g_MenuPanelTaskCurrent->unk_10 >> 4), (u8)(g_MenuPanelTaskCurrent->unk_12 >> 4));
    }
    if (g_MenuPanelTaskCurrent->unk_00[2] == 0) {
        UI_UpdateLayout();
    }
}
