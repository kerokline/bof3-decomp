#include "area033_13.h"

/* func_801F390C */
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
    sprt->w  = D_801F4FA0[idx];
    sprt->h  = D_801F4FA1[idx];
    sprt->u0 = D_801F4FA2[idx];
    sprt->v0 = D_801F4FA3[idx];

    GFX_AddPrim(1, 0x14);
}
