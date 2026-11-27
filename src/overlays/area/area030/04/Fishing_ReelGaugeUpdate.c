#include "area030_04.h"

/* func_801D2DC4 */
/* Reel gauge: moves the cursor toward the hooked fish's limit, then draws the gauge line, the
 * cursor row and the fish arrow. */
MATCH void Fishing_ReelGaugeUpdate(void) {
    LINE_F2*      prim;
    FishingState* work;
    FishingState* gauge;
    FishingState* panel;
    s16           cursor;
    s16           line;
    s16           marker_y;
    s16           fish_y;
    s16           arrow_y;
    s16           origin;
    s8            limit;
    s32           step;
    s16           bound;
    u8            band;
    u8            size;
    u8            timer;
    s8            flip;

    Fishing_SetDrawMode(0, 2);
    Fishing_DrawSprite(0x11, 2, 135, 180);
    work = SELF(FishingState);
    if (work->cursor_10 == 0) {
        limit  = (s8)g_Actors[g_FishingHookedFish].unk_0A;
        origin = work->origin_y;
        step   = g_FishingRodRow->reel_cursor_size * 4;
        if ((origin + step + 12 < limit) || (limit < origin - step - 12)) {
            timer = work->timer;
            if (timer >= 15) {
                if (limit < origin) {
                    /* FAKE: the loop weight lifts the work pointer over the fish limit in the allocator (a0 above a1); pure C best 13 rows. */
                    do {
                        work->cursor_10 = -1;
                    } while (0);
                } else if (origin < limit) {
                    work->cursor_10 = 1;
                }
            } else {
                work->timer = timer + 1;
            }
            goto moved;
        }
    }
    work->timer = 0;
moved:
    LOH(SELF(FishingState)->origin_y) += SELF(FishingState)->cursor_10;
    gauge  = SELF(FishingState);
    cursor = gauge->origin_y;
    if (cursor < g_FishingRodRow->reel_cursor_size * 4 - 36) {
        bound = g_FishingRodRow->reel_cursor_size * 4 - 36;
    } else {
        bound = 36 - g_FishingRodRow->reel_cursor_size * 4;
        if (bound >= cursor) {
            bound = gauge->origin_y;
        }
    }
    gauge->origin_y = bound;
    prim            = (LINE_F2*)g_GfxPrimCursor;
    SetLineF2(prim);
    prim->x0 = 185;
    prim->x1 = 185;
    prim->y0 = 201;
    prim->y1 = 213;
    setRGB0(prim, 128, 128, 128);
    GFX_AddPrim(GFX_LAYER_EFFECT_FRONT, sizeof(LINE_F2));

    size     = g_FishingRodRow->reel_cursor_size;
    panel    = SELF(FishingState);
    band     = size * 8 + 24;
    line     = panel->origin_y - size * 4 + 173;
    marker_y = line + size * 8 + 24;
    fish_y   = (s8)g_Actors[g_FishingHookedFish].unk_0A + 185;
    if ((fish_y > marker_y) || (fish_y < line)) {
        Fishing_DrawReelCursor(line, 203, band, (panel->step_index & 7) * 2, 2, 1);
    } else {
        Fishing_DrawReelCursor(line, 203, band, (panel->step_index & 7) * 2, 2, 0);
    }
    if (g_Actors[g_FishingHookedFish].header.mode == 4) {
        prim = (LINE_F2*)g_GfxPrimCursor;
        SetLineF2(prim);
        prim->x0 = 136;
        prim->x1 = g_Actors[g_FishingHookedFish].ext.bounds.half_height * 96 / 256 + 136;
        prim->y0 = 211;
        prim->y1 = 211;
        setRGB0(prim, 128, 0, 0);
        GFX_AddPrim(GFX_LAYER_EFFECT_FRONT, sizeof(LINE_F2));

        flip    = g_Actors[g_FishingHookedFish].vy >= 0;
        arrow_y = fish_y < 144 ? 144 : fish_y > 228 ? 228 : fish_y;
        Fishing_DrawFishArrow(arrow_y, 203, flip, 2);
        if (D_80145E92[0] == 4 && g_Actors[g_FishingHookedFish].unk_04 != 3 && (marker_y < arrow_y || arrow_y < line) && !(g_FrameCount & 0xF)) {
            SND_SEPlay(EMI_SE_ID(SND_BANK_AREA, 7));
        }
    }
}
