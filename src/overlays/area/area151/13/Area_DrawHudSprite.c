#include "area151_13.h"

/* func_801F3948 */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = D_801F5468[idx];
    sprt->h  = D_801F5469[idx];
    sprt->u0 = D_801F546A[idx];
    sprt->v0 = D_801F546B[idx];

    GFX_AddPrim(1, 0x14);
}
