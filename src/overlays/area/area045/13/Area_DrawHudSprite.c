#include "area045_13.h"

/* func_801F39D8 */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = ((u8*)D_801F5364 + 0x10)[idx];
    sprt->h  = ((u8*)D_801F5364 + 0x10)[idx + 1];
    sprt->u0 = ((u8*)D_801F5364 + 0x10)[idx + 2];
    sprt->v0 = ((u8*)D_801F5364 + 0x10)[idx + 3];

    GFX_AddPrim(1, 0x14);
}
