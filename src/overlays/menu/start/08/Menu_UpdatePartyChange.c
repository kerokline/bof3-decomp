#include "start_08.h"

/* func_801DA474 */
MATCH void Menu_UpdatePartyChange(void) {
    u8*          clut;
    volatile u8* frame;
    u8*          side;
    s8*          row;
    s32          next;
    s32          input;
    s32          index;
    u8           count;
    u8           old_side;
    u8           old_row;
    u8           result;
    u16          y;

    clut = &g_WindowClut;
    Menu_DrawClutStrip(*clut);
    frame                                                = &D_801485DC;
    *frame                                               = 0;
    index                                                = D_80148658[0] * 8 + D_80148659 * 0x10;
    D_80148600                                           = 0;
    D_801485E0                                           = FIELD(u16, &D_801EC548, index);
    y                                                    = FIELD(u16, &D_801EC54A, index);
    *frame                                               = 1;
    D_801485E2                                           = y;
    g_UiPanelTasks[MENU_START_PANEL_CURSOR_FRAME].unk_0A = FIELD(s32, &D_801EC54C, index);
    g_UiPanelTasks[MENU_START_PANEL_CURSOR_FRAME].unk_0B = 1;
    if ((s8)D_8014865D != 0x7F) {
        s32 cell;
        u16 y2;

        cell                      = (s8)D_8014865A * 8 + (s8)D_8014865D * 0x10;
        g_UiPanelTasks[20].pos.x  = FIELD(u16, &D_801EC548, cell);
        y2                        = FIELD(u16, &D_801EC54A, cell);
        D_80148600                = 1;
        g_UiPanelTasks[20].pos.y  = y2;
        g_UiPanelTasks[20].unk_0A = FIELD(s32, &D_801EC54C, cell);
        g_UiPanelTasks[20].unk_0B = 0;
    }
    if (D_801ED69C == GAME_NONE) {
        D_801484CC = 0x60;
    } else {
        s32 offset;
        u8* name;

        offset = g_CharSlot[D_801ED69C] * 0xA4;
        name   = clut + 0x15;
        UI_MessageSetVariable(0, 5, name + offset);
        D_801484CC = 0x61;
    }
    input    = INPUT_REPEATED(g_PadStates[0].pressed, INPUT_DIRECTIONAL);
    count    = Party_CountOrder(PARTY_ORDER_FIELD);
    side     = (u8*)D_80148658;
    old_side = *side;
    old_row  = D_80148659;
    if ((input & (PADLright | PADLleft)) && g_UiPanelTasks[MENU_START_PANEL_COMMANDS].unk_0A != 0) {
        *side = old_side ^ 1;
    }
    if (D_80148658[0] == 0) {
        if (count - 1 < D_80148659) {
            D_80148659 = count - 1;
        }
    } else if (g_UiPanelTasks[MENU_START_PANEL_COMMANDS].unk_0A - 1 < D_80148659) {
        D_80148659 = g_UiPanelTasks[MENU_START_PANEL_COMMANDS].unk_0A - 1;
    }
    if (input & PADLup) {
        row = &D_80148659;
        *row -= 1;
        if (*row < 0) {
            *row = D_80148658[0] == 0 ? count - 1 : g_UiPanelTasks[MENU_START_PANEL_COMMANDS].unk_0A - 1;
        }
    } else if (input & PADLdown) {
        s8* down = &D_80148659;

        next = ++*down;
        if ((D_80148658[0] == 0 && count - 1 < next) || (D_80148658[0] != 0 && g_UiPanelTasks[MENU_START_PANEL_COMMANDS].unk_0A - 1 < next)) {
            D_80148659 = 0;
        }
    }
    if (old_side != (u8)D_80148658[0] || old_row != (u8)D_80148659) {
        SND_SEPlay(EMI_SE_ID(SND_BANK_COMMON, 0));
    }
    if (g_PadStates[0].pressed & g_InputMasks[MENU_INPUT_CONFIRM]) {
        s8* pick = (s8*)&D_8014865A;

        if (*pick == 0x7F) {
            SND_SEPlay(EMI_SE_ID(SND_BANK_COMMON, 3));
            *pick      = D_80148658[0];
            D_8014865D = D_80148659;
            return;
        }
        result     = Menu_SwapPartyMembers();
        D_801ED69C = result;
        SND_SEPlay(result == GAME_NONE ? EMI_SE_ID(SND_BANK_COMMON, 3) : EMI_SE_ID(SND_BANK_COMMON, 7));
        D_8014865A = 0x7F;
        D_8014865D = 0x7F;
        return;
    }
    if (g_PadStates[0].pressed & g_InputMasks[MENU_INPUT_CANCEL]) {
        s8* pick;

        SND_SEPlay(EMI_SE_ID(SND_BANK_COMMON, 6));
        pick = (s8*)&D_8014865A;
        if (*pick != 0x7F) {
            *pick      = 0x7F;
            D_8014865D = 0x7F;
            return;
        }
        D_80148654 = 5;
        D_801485DC = 0;
        D_80148600 = 0;
        D_801484E3 = 1;
        D_80148652 += 1;
    }
}
