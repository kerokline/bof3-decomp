#include "batl_end_00.h"

/* The window colour of the current window style: one 15-bit colour word in the panel colour bank. */
#define WINDOW_STYLE_COLOR MEM(u16, AREA_PALETTE_ARENA_33A00 + 8 + (((*(s8*)&g_WindowStyle) << 6) | 0x20))

/* Draws a victory result window's frame: a half-transparent tile in the window colour, the top and bottom edge
 * shapes and the four border lines. */
MATCH void func_801F039C(s16 x, s16 y, s16 width, s16 height) {
    TILE* tile;
    u16   color;
    s32   r;
    s32   g;
    s32   b;

    GFX_ADD_DRAW_MODE(GetTPage(TPAGE_DEPTH_4BIT, TPAGE_ABR_HALF, FONT_TPAGE_X, FONT_TPAGE_Y));
    tile = (TILE*)g_GfxPrimCursor;
    SetTile(tile);
    setXY0(tile, x, y + 2);
    setWH(tile, width, height);
    setRGB0(tile, (WINDOW_STYLE_COLOR & 0x1F) * 8, (WINDOW_STYLE_COLOR >> 2) & 0xF8, (WINDOW_STYLE_COLOR >> 7) & 0xF8);
    SetSemiTrans(tile, 1);
    GFX_AddPrim(1, 0x10);
    color = WINDOW_STYLE_COLOR;
    r     = (color & 0x1F) << 3;
    g     = (color >> 2) & 0xF8;
    b     = (color >> 7) & 0xF8;
    func_801D9AB4(x, y, 8, 1);
    func_801D9AB4(x, y + height + 2, 9, 1);
    func_801DA5A8(x + 2, y + 2, x + width - 3, y + 2, r, g, b);
    height++;
    func_801DA5A8(x + 2, y + 3, x + 2, y + height, r, g, b);
    func_801DA4B4(x + width - 3, y + 2, x + width - 3, y + height, r, g, b);
    func_801DA4B4(x + 2, y + height, x + width - 3, y + height, r, g, b);
}
