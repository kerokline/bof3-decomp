#include "area148_13.h"

MATCH void func_801F4DF0(s32 x, s32 y, s16 radius, u16 angle) {
    POLY_G3* prim;
    u8       i;

    i = 0;
    do {
        prim = GFX_BeginPolyG3(1);
        setXY2(prim, x, y, x + FIXED_MUL(radius, rcos(angle)), y + FIXED_MUL(radius, rsin(angle)));
        angle += ANGLE_45 / 2;
        prim->x2 = x + FIXED_MUL(radius, rcos(angle));
        prim->y2 = y + FIXED_MUL(radius, rsin(angle));
        prim->r0 = D_801F6138[SELF(Actor)->unk_06][0];
        prim->g0 = D_801F6138[SELF(Actor)->unk_06][1];
        prim->b0 = D_801F6138[SELF(Actor)->unk_06][2];
        setRGB1(prim, 0, 0, 0);
        setRGB2(prim, 0, 0, 0);
        {
            Coord cell_x = {SELF(Actor)->unk_18};
            Coord cell_y = {SELF(Actor)->unk_1C};

            Area_CellAddPrim(cell_x.fixed, cell_y.fixed, 0, sizeof(POLY_G3));
        }
        i += 1;
    } while (i < 8);
}
