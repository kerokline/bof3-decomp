#include "area104_14.h"

/* func_801F3A9C */
MATCH void Area_DrawHudSprite(s32 x, s32 y, u32 sprite_id) {
    SPRT* sprt;
    s32   tpage;
    s32   idx;

    tpage = getTPage(1, 0, 768, 256);
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 0, tpage, 0);
    GFX_AddPrim(1, 0xC);

    sprt = (SPRT*)g_GfxPrimCursor;
    SetSprt(sprt);
    SetSemiTrans(sprt, 1);
    setRGB0(sprt, 128, 128, 128);
    sprt->x0   = x;
    sprt->y0   = y;
    sprt->clut = 0x7B80;

    idx      = (sprite_id & BYTE_MASK) << 2;
    sprt->w  = D_801F6AA0[idx];
    sprt->h  = D_801F6AA0[idx + 1];
    sprt->u0 = D_801F6AA0[idx + 2];
    sprt->v0 = D_801F6AA0[idx + 3];

    GFX_AddPrim(1, 0x14);
}
