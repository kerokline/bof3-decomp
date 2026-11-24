#include "battle_03.h"

/* Draws a battle gauge bar 7 high: the body stretched over its width, lit or dim by the flag, then its end cap. */
MATCH void func_801D9E9C(s32 x, s32 y, s32 width, s32 second_width, u8 second) {
    POLY_FT4* poly;
    s32       flag;

    poly = (POLY_FT4*)g_GfxPrimCursor;
    flag = second;
    SetPolyFT4(poly);
    poly->tpage = GetTPage(TPAGE_DEPTH_4BIT, TPAGE_ABR_HALF, FONT_TPAGE_X, FONT_TPAGE_Y);
    if (flag == 0) {
        poly->clut = GetClut(0xE0, STAGE_PALETTE_Y);
    } else {
        poly->clut = GetClut(0xB0, STAGE_PALETTE_Y);
    }
    setRGB0(poly, GFX_COLOR_NEUTRAL, GFX_COLOR_NEUTRAL, GFX_COLOR_NEUTRAL);
    setXYWH(poly, x, y, width & BYTE_MASK, 7);
    if (flag == 0) {
        setUVWH(poly, 0x90, 0xD8, 7, 7);
    } else {
        setUVWH(poly, 0x80, 0xD8, 7, 7);
    }
    GFX_AddPrim(GFX_LAYER_UI, sizeof(POLY_FT4));

    poly = (POLY_FT4*)g_GfxPrimCursor;
    SetPolyFT4(poly);
    poly->tpage = GetTPage(TPAGE_DEPTH_4BIT, TPAGE_ABR_HALF, FONT_TPAGE_X, FONT_TPAGE_Y);
    poly->clut  = GetClut(0xB0, STAGE_PALETTE_Y);
    setRGB0(poly, GFX_COLOR_NEUTRAL, GFX_COLOR_NEUTRAL, GFX_COLOR_NEUTRAL);
    setXYWH(poly, x + (width & BYTE_MASK), y, (u8)second_width, 7);
    setUVWH(poly, 0x98, 0xD8, 7, 7);
    GFX_AddPrim(GFX_LAYER_UI, sizeof(POLY_FT4));
}
