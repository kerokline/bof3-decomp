#include "area065_13.h"

/* func_801F3A10 */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    GFX_SET_DRAW_MODE(tpage);
    GFX_AddPrim(1, 0xC);

    sprt = GfxBeginSprite(x, y, WORLD_SPRITE_CLUT);

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = ((u8*)D_801F4DB4 + 0x4FC)[idx];
    sprt->h  = ((u8*)D_801F4DB4 + 0x4FC)[idx + 1];
    sprt->u0 = ((u8*)D_801F4DB4 + 0x4FC)[idx + 2];
    sprt->v0 = ((u8*)D_801F4DB4 + 0x4FC)[idx + 3];

    GFX_AddPrim(1, 0x14);
}
