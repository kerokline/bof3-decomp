#include "shop_00.h"

#ifdef NON_MATCHING
NON_MATCHING void func_801D1A90(void) {
    s32            buttons;
    u8             cursor;
    MenuPanelTask* panel;

    panel = &g_MenuPanelTasks[9];
    /* FAKE: the panel store stays above the pad-state read, as retail orders them. */
    MATCH_FAKE_BARRIER();
    panel->unk_00[0] = 1;
    D_80148475       = 7;
    D_80148476       = 8;
    D_80148478       = panel[-1].x;
    D_8014845A       = 1;
    buttons          = panel[-1].y + 0x2D;
    D_8014847F       = D_801E6044;
    D_80148480       = D_801E6050;
    D_80148494       = D_8018E7CC;
    D_8014847A       = buttons;
    D_8014847E       = D_801E6064;
    D_80148628       = panel[-1].x + 4;
    D_8014862A       = panel[-1].y + 0x33;
    D_80148340       = D_801E6050 != 0 ? 0x48 : 0x4E;
    buttons          = INPUT_REPEATED(g_InputPressed, INPUT_DIRECTIONAL);
    cursor           = D_801E6050;
    if (buttons & PADLleft) {
        D_801E6050 = cursor - 1;
    } else if (buttons & PADLright) {
        D_801E6050 = cursor + 1;
    }
    if ((s8)D_801E6050 <= 0) {
        D_801E6050 = 1;
    }
    if ((u8)D_801E605C < D_801E6050) {
        D_801E6050 = D_801E605C;
    }
    if (cursor != D_801E6050) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
    }
    if (buttons & PADLdown) {
        D_801E6050 -= 0xA;
    } else if (buttons & PADLup) {
        D_801E6050 += 0xA;
    }
    if ((s8)D_801E6050 <= 0) {
        D_801E6050 = 1;
    }
    if ((u8)D_801E605C < D_801E6050) {
        D_801E6050 = D_801E605C;
    }
    if (cursor != D_801E6050) {
        SND_PlayCue(EMI_CUE_ID(1, 0));
    }
    if (g_InputPressed & D_80145AC2) {
        if (D_801E6050 != 0) {
            SND_PlayCue(EMI_CUE_ID(1, 3));
            D_8014865B = 1;
            D_80148652 += 1;
        } else {
            SND_PlayCue(EMI_CUE_ID(1, 7));
        }
    } else if (g_InputPressed & D_80145AC4) {
        SND_PlayCue(EMI_CUE_ID(1, 6));
        (*(s8*)&D_80148652)--;
    }
}
#else
INCLUDE_ASM(func_801D1A90);
#endif
