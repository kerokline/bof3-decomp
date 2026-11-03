#include "area088_13.h"

/* One byte per sprite id in each of four tables: width, height, u0, v0. */
/* func_801F453C */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = D_801F61DC[idx];
    sprt->h  = D_801F61DD[idx];
    sprt->u0 = D_801F61DE[idx];
    sprt->v0 = D_801F61DF[idx];

    GFX_AddPrim(1, 0x14);
}
