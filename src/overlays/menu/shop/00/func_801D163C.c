#include "shop_00.h"

MATCH void func_801D163C(void) {
    u8*            entry;
    u8*            pick;
    s32            input;
    s32            held;
    u8             old;
    u8             i;
    u8             choice;
    MenuPanelTask* panel;
    MenuPanelTask* panels;

    entry                      = D_8018E7CC + D_801E6044 * 2;
    D_801E6048                 = entry[1];
    i                          = 0;
    choice                     = entry[2];
    g_MenuPanelTasks[8].unk_0A = 0;
    D_801E604C                 = choice;
    panels                     = &g_MenuPanelTasks[3];
    for (; i < (u8)Party_CountOrder(0); i++) {
        panel         = (MenuPanelTask*)(i * sizeof(MenuPanelTask) + (u32)panels);
        panel->unk_0B = Item_GetKind(D_801E6048, D_801E604C);
        panel->unk_0C = D_801E604C;
    }
    g_MenuPanelTasks[0].unk_10 = Item_GetDescription(D_801E6048, D_801E604C);
    D_80148474                 = 0;
    if (D_80148453 == 0) {
        /* FAKE: block boundary keeps the panel-task stores base-relative off one la. */
        ORDER_LOCK((void)0);
        g_MenuPanelTasks[21].unk_00[0] = 1;
        D_80148628                     = (u16)D_80148454 + 4;
        D_8014862A                     = (u16)D_80148456 + D_801E6044 * 0xD + 0xA;
        D_80148644                     = D_8018E7CC;
    }
    input = INPUT_REPEATED(g_InputPressed, (PADLup | PADLdown));
    old   = D_801E6044;
    if (input & PADLup) {
        if ((D_801E6044 = old - 1) < 0) {
            D_801E6044 = *D_8018E7CC - 1;
        }
    } else if (input & PADLdown) {
        if ((D_801E6044 = old + 1) > (s8)*D_8018E7CC - 1) {
            D_801E6044 = 0;
        }
    }
    if ((s8)old != D_801E6044) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
    }
    D_8014845C = D_801E6044;
    if (g_InputPressed & D_80145AC2) {
        pick       = D_8018E7CC + D_801E6044 * 2;
        D_801E6048 = pick[1];
        D_801E604C = pick[2];
        D_801E6050 = 1;
        D_801E6060 = Shop_ApplyPercent(Item_GetPrice(D_801E6048, D_801E604C), D_801E6064);
        D_801E605C = g_Zenny / (u32)D_801E6060;
        held       = Party_CountItem(D_801E6048, D_801E604C, 0) + Party_CountItem(D_801E6048, D_801E604C, 1);
        if ((u8)held >= 100) {
            D_801E6050 = 0;
            D_801E605C = 0;
        } else if ((u8)(99 - held) < (u32)D_801E605C) {
            D_801E605C = (u8)(99 - held);
            if (D_801E605C != 0) {
                D_801E6050 = 1;
            } else {
                D_801E6050 = 0;
            }
        }
        if (g_Zenny >= (u32)D_801E6060) {
            D_8014865B = 1;
            SND_PlayCue(EMI_CUE_ID(1, 3));
            D_80148652 += 1;
        } else {
            SND_PlayCue(EMI_CUE_ID(1, 7));
        }
    } else if (g_InputPressed & D_80145AC4) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        for (i = 0; i < (u8)Party_CountOrder(0); i++) {
            g_MenuPanelTasks[i + 3].state = 1;
        }
        D_80148453 = 1;
        D_80148651 = 1;
        D_80148652 = 0;
    }
}
