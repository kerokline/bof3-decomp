#include "battle_03.h"

MATCH void func_801D9900(void) {
    TILE* tile;

    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 0, GetTPage(0, 2, 960, 0), 0);
    GFX_AddPrim(1, 0x0C);
    tile = (TILE*)g_GfxPrimCursor;
    SetTile(tile);
    tile->w  = 960;
    tile->h  = 240;
    tile->x0 = 0;
    tile->y0 = 0;
    setRGB0(tile, 40, 40, 40);
    PSX_SET_SEMI_TRANSPARENT(tile);
    GFX_AddPrim(1, 0x10);
}
