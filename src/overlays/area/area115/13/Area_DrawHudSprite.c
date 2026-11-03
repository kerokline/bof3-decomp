#include "area115_13.h"

/* func_801F39DC */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    /* One four-byte cell per sprite id: w, h, u0, v0. */
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = D_801F4F84[idx];
    sprt->h  = D_801F4F84[idx + 1];
    sprt->u0 = D_801F4F84[idx + 2];
    sprt->v0 = D_801F4F84[idx + 3];

    GFX_AddPrim(1, 0x14);
}
