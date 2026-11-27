#include "area189_13.h"

#include <inline_c.h>

/* Draws the visible band of the map: the two per-buffer lists of every grid row are emptied, then
 * each cell of the rotated band is projected, culled against the screen box, textured, and linked
 * into the list its row and the draw buffer select. */
#ifdef NON_MATCHING
NON_MATCHING void func_801F2DE0(void) {
    u8*       base;
    u8*       next;
    s8*       rec;
    u32       level;
    u32       address;
    u32       row_offset;
    u32       column_offset;
    u32       slot_offset;
    u32       offset;
    s32       row;
    s32       col;
    s32       angle;
    s32       orientation;
    s32       side;
    s32       idx;
    s32       x;
    s32       y;
    s32       cell_index;
    u32       texture;
    u16       cell;
    u16       ux;
    u16       uy;
    u8        block;
    s16       sx;
    s16       sy;
    u16       slot;
    POLY_FT4* prim;
    POLY_FT4* cells;

    row                   = 0;
    base                  = (u8*)&D_80142CC0;
    level                 = g_GfxBufferIndex;
    row_offset            = 0;
    g_AreaCellPacketCount = 0;
    do {
        col           = 0;
        offset        = row_offset;
        column_offset = level;
        do {
            address = column_offset << 3;
            col++;
            slot_offset                       = address + offset;
            address                           = address + base;
            *(u32*)(D_80142CC4 + slot_offset) = offset + address;
            *(u32*)(D_80142CC0 + slot_offset) = 0;
            column_offset += 2;
        } while (col < 2);
        row++;
        row_offset += 0x30;
    } while (row < AREA_CELL_GRID_ROWS);

    angle                        = (g_AreaCameraAngle.vz + 0x100) >> 9;
    orientation                  = angle & 7;
    side                         = (angle & 1) ^ 1;
    sx                           = (s8)D_801F6108[orientation * 6] - (((((u32)g_AreaCameraX >> 8) + 0x80) & 0xFF) - 0x100);
    g_ScratchPad.cells.halves[0] = sx;
    g_AreaTileOriginX            = sx;
    sy                           = (s8)D_801F6108[orientation * 6 + 3] - (((((u32)g_AreaCameraY >> 8) + 0x80) & 0xFF) - 0x100);
    g_ScratchPad.cells.words[1]  = AREA_CELL_GRID_ROWS - side * 12;
    g_ScratchPad.cells.words[2]  = side * 12 + AREA_CELL_GRID_COLS;
    g_AreaCellPrimFreeIndex      = 0;
    g_ScratchPad.cells.halves[1] = sy;
    g_AreaTileOriginY            = sy;

    for (row = 0; row < g_ScratchPad.cells.words[1]; row++) {
        for (col = 0; col < g_ScratchPad.cells.words[2]; col++) {
            if (g_AreaCellPrimFreeIndex >= 0x400) {
                continue;
            }
            idx = orientation * 6;
            x   = g_ScratchPad.cells.halves[0] + col * (s8)D_801F6108[idx + 1] + row * (s8)D_801F6108[idx + 2] / 2;
            y   = g_ScratchPad.cells.halves[1] + col * (s8)D_801F6108[idx + 4] + (row + 1) * (s8)D_801F6108[idx + 5] / 2;

            block                     = D_801F6138[(y & 0xF0) | ((x & 0xF0) >> 4)];
            g_ScratchPadVectors[0].vx = (x << 7) - (AREA_CELL_ORIGIN + AREA_CELL_HALF);
            g_ScratchPadVectors[0].vy = (y << 7) - (AREA_CELL_ORIGIN + AREA_CELL_HALF);
            cell_index                = ((block & 0xF0) | (y & 0xF)) * 0x60 + (((block & 0xF) << 4) | (x & 0xF));
            rec                       = (s8*)(MAP_BUNDLE_BASE + AREA_MAP_BUNDLE_SIZE + cell_index * 4);
            D_1F800010                = rec;
            g_ScratchPadVectors[0].vz = -(rec[0] * 16);
            gte_ldv0(&g_ScratchPadVectors[0]);
            gte_rtps();
            gte_stsxy(&D_1F800034[0]);
            if (D_1F800034[1] >= 0x79) {
                if ((u16)(D_1F800034[0] + 0xC7) < 0x2CF) {
                    goto draw;
                }
                continue;
            } else if ((u16)(D_1F800034[0] + 0x31) >= 0x1A3) {
                continue;
            }
        draw:
            slot                    = g_AreaCellPrimFreeIndex;
            g_AreaCellPrimFreeIndex = slot + 1;
            cells                   = g_AreaCellPrims[slot];
            cell                    = MEM(u16, MAP_BUNDLE_BASE + AREA_MAP_BUNDLE->grid_offset * 4 + cell_index * 2);
            texture                 = MEM(u32, MAP_BUNDLE_BASE + AREA_MAP_BUNDLE->grid_offset * 4 + ((AREA_MAP_BUNDLE->width * AREA_MAP_BUNDLE->height + 1) >> 1) * 4 + cell * 4);
            Area_CellSetTexture(texture, &cells[g_GfxBufferIndex]);

            prim                       = &cells[g_GfxBufferIndex];
            *(u32*)&prim->x0           = *(u32*)D_1F800034;
            rec                        = D_1F800010;
            g_ScratchPad.vectors[1].vx = (ux = g_ScratchPad.vectors[0].vx) + 0x80;
            D_1F80001C.vy = uy         = g_ScratchPad.vectors[0].vy;
            D_1F80001C.vz              = -(((*(s32*)rec << 16) >> 24) * 16);
            g_ScratchPad.vectors[2].vx = ux;
            g_ScratchPad.vectors[2].vy = uy + 0x80;
            g_ScratchPad.vectors[2].vz = -(rec[2] * 16);
            g_ScratchPadVectors[3].vx  = ux + 0x80;
            g_ScratchPadVectors[3].vy  = uy + 0x80;
            g_ScratchPadVectors[3].vz  = -(rec[3] * 16);
            gte_ldv3c(&g_ScratchPadVectors[1]);
            gte_rtpt();

            offset = (AREA_CELL_GRID_ROWS - 1 - row) * 0x30 + g_GfxBufferIndex * 8;
            next   = *(u8**)(D_80142CC4 + offset);
            setaddr(next, prim);
            *(u8**)(D_80142CC4 + offset) = (u8*)prim;
            gte_stsxy3(&prim->x1, &prim->x2, &prim->x3);
        }
    }
}
#else
INCLUDE_ASM(func_801F2DE0);
#endif
