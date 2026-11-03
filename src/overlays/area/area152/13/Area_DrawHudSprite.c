#include "area152_13.h"

/* One four-byte cell per sprite id: w, h, u0, v0. */

/* func_801F389C */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = D_801F4C3C[0x158 + idx];
    sprt->h  = D_801F4C3C[0x159 + idx];
    sprt->u0 = D_801F4C3C[0x15A + idx];
    sprt->v0 = D_801F4C3C[0x15B + idx];

    GFX_AddPrim(1, 0x14);
}
