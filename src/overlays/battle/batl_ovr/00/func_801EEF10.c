#include "batl_ovr_00.h"

/* Grows the defeat bar and, on a held button, greys the battle overlay's palette row and its mirror before the long
 * fade out. */
MATCH void func_801EEF10(void) {
    u16* fade;
    u8*  step;
    u16  i;

    func_801EF318();
    func_801EF180(128);
    func_801EF3B4(128);

    fade = &D_801463B0;
    if (*fade < 244) {
        *fade += 4;
    }
    func_801EF47C(*fade);

    if (g_PadStates[0].held != 0) {
        for (i = 0; i < AREA_PALETTE_COLORS; i++) {
            u16 color;
            u32 gray;
            u16 value;

            color                                                               = MEM_PTR(u16, AREA_PALETTE_UPLOAD_ROW(AREA_PALETTE_BATL_OVR_ROW))[i];
            gray                                                                = (PSX_COLOR_R(color) + PSX_COLOR_G(color) + PSX_COLOR_B(color)) / 3U;
            value                                                               = gray | ((color & PSX_COLOR_STP_BIT) | (gray << 10) | (gray << 5));
            MEM_PTR(u16, AREA_PALETTE_UPLOAD_ROW(AREA_PALETTE_BATL_OVR_ROW))[i] = value;
        }
        for (i = 0; i < AREA_PALETTE_COLORS; i++) {
            u16 color;
            u32 gray;
            u16 value;

            color                      = GAME_PALETTE_MIRROR_U16[i];
            gray                       = (PSX_COLOR_R(color) + PSX_COLOR_G(color) + PSX_COLOR_B(color)) / 3U;
            value                      = gray | ((color & PSX_COLOR_STP_BIT) | (gray << 10) | (gray << 5));
            GAME_PALETTE_MIRROR_U16[i] = value;
        }
        g_GfxPalettePending = 1;
        UI_ModeSet(UI_MODE_LONG_FADE_OUT);
        step = &g_BattleUIStep;
        (*step)++;
    }
}
