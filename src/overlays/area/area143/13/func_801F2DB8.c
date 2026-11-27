#include "area143_13.h"

MATCH void func_801F2DB8(SpriteSpark* spark) {
    TILE_1* tile1;
    TILE*   tile;

    if (spark->blink != 0) {
        tile1 = (TILE_1*)g_GfxPrimCursor;
        SetTile1(tile1);
        Camera_ProjectPoint(&spark->pos.vx, (DVECTOR*)&tile1->x0);
        tile1->b0 = 0;
        tile1->g0 = 0;
        tile1->r0 = 0;
        {
            Coord cell_x = {spark->pos.vx};
            Coord cell_y = {spark->pos.vy};

            Area_CellAddPrim(cell_x.fixed, cell_y.fixed, 0, sizeof(TILE_1));
        }

        SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 0, GetTPage(TPAGE_DEPTH_4BIT, TPAGE_ABR_SUB, 0x3C0, 0), 0);
        {
            Coord cell_x = {spark->pos.vx};
            Coord cell_y = {spark->pos.vy};

            Area_CellAddPrim(cell_x.fixed, cell_y.fixed, 0, sizeof(DR_MODE));
        }

        tile = (TILE*)g_GfxPrimCursor;
        SetTile(tile);
        SetSemiTrans(tile, 1);
        Camera_ProjectPoint(&spark->pos.vx, (DVECTOR*)&tile->x0);
        setWH(tile, 3, 3);
        tile->b0 = 8;
        tile->g0 = 8;
        tile->r0 = 8;
        tile->x0 -= 1;
        tile->y0 -= 1;
        {
            Coord cell_x = {spark->pos.vx};
            Coord cell_y = {spark->pos.vy};

            Area_CellAddPrim(cell_x.fixed, cell_y.fixed, 0, sizeof(TILE));
        }
    }
}
