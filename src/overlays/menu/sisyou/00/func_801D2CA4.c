#include "sisyou_00.h"

/* Main-RAM shop state, lookup tables, and working buffers. */

/* Overlay-local master stats: 6 signed stat-bonus bytes per master id. */

MATCH void func_801D2CA4(void) {
    s32 i;
    u8* edp;

    if (g_MasterBannerLock != 0) {
        Message_StartAreaMessage((s16)(D_801D41BC[D_801448ED] + 4));
        g_GameStateIndex = GAME_REQUEST_MESSAGE;
        g_MasterStep     = 6;
        g_MasterSubStep  = 0;
    } else {
        i = 0;
        do {
            /* FAKE: shift form avoids the phantom stack slot * 0x140
             * allocates. */
            g_TextVariables[0][i] = g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].name[i];
            i += 1;
        } while (i < 5);
        D_801490DD                                                              = 0;
        edp                                                                     = &D_801448ED;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].master_id = *edp;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].unk_84 =
            g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[0] = D_801D4154[*edp].hp;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[1] = D_801D4154[*edp].ap;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[2] = D_801D4154[*edp].power;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[3] = D_801D4154[*edp].defense;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[4] = D_801D4154[*edp].agility;
        g_Characters[D_80145FCC.bytes[(g_MasterMenuCursor * 5) << 6]].level_up_modifiers[5] =
            D_801D4154[*edp].intellect;
        Message_StartAreaMessage((s16)(D_801D41BC[*edp] + 10));
        g_GameStateIndex = GAME_REQUEST_MESSAGE;
        g_MasterSubStep += 1;
    }
}
