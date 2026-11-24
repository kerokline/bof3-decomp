#include "area040_13.h"

/* Each 4x4 cell with code 0x50 and a cell id gets a flat quad at its corners, grey pulsing with the frame. */
MATCH void func_801F37D4(void) {
    POLY_F4* prim;
    s32      shade;
    s32      id;
    s32      x;
    u8       i;
    s32      j;

    for (i = 0; i < 4; i++) {
        for (j = 0; (u8)j < 4; j++) {
            if ((u8)Area_CellGetCode((j & BYTE_MASK) + 0x94, (s16)(i + 0x20)) != 0x50) {
                continue;
            }
            x  = ((u8)j) + 0x94;
            id = Area_CellGetId(x, i + 0x20);
            if (id == 0) {
                continue;
            }
            prim = (POLY_F4*)g_GfxPrimCursor;
            SetPolyF4(prim);
            SetSemiTrans(prim, 1);
            prim->x0 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].x0, prim->y0 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].y0,
            prim->x1 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].x1, prim->y1 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].y1,
            prim->x2 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].x2, prim->y2 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].y2,
            prim->x3 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].x3, prim->y3 = g_AreaCellPrims[id][(g_GfxBufferIndex) ? (0) : (1)].y3;
            shade    = ((g_FrameCount >> 1) & 0xF) - 8;
            shade    = (shade < 0 ? -shade : shade) * 31;
            prim->r0 = (prim->g0 = (prim->b0 = shade));
            Area_CellAddPrim(x << 16, (i + 0x20) << 16, 0, sizeof(POLY_F4));
        }
    }
}
