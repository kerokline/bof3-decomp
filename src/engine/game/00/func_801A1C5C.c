#include "game_00.h"

#define AREA_CELL_BLOCKED(x, y) ((u8 (*)(s32, s32))Area_CellIsBlocked)((x), (y))

#ifdef NON_MATCHING
NON_MATCHING s32 func_801A1C5C(s32 x, s32 y, s32 route, s32 unused) {
    u8  sum;
    s32 along;
    s32 column;

    switch (route & BYTE_MASK) {
        case FACING_UP: {
            s32 row;

            along = x >> 16;
            row   = (y >> 16) & HALF_MASK;
            sum   = AREA_CELL_BLOCKED(along & HALF_MASK, row);
            sum += AREA_CELL_BLOCKED((along + 1) & HALF_MASK, row);
            if (!(x & HALF_MASK)) {
                sum += AREA_CELL_BLOCKED((along - 1) & HALF_MASK, row);
            }
            sum += func_801A21EC(x, y);
            sum += func_801A21EC(x + COORD_HALF, y);
            sum += func_801A21EC(x - COORD_HALF, y);
            break;
        }
        case FACING_DOWN:
            if (y & HALF_MASK) {
                s32 col = x >> 16;

                sum = AREA_CELL_BLOCKED(col & HALF_MASK, ((y >> 16) + 1) & HALF_MASK);
                sum += AREA_CELL_BLOCKED((col + 1) & HALF_MASK, ((y >> 16) + 1) & HALF_MASK);
                if (!(x & HALF_MASK)) {
                    sum += AREA_CELL_BLOCKED((col - 1) & HALF_MASK, ((y >> 16) + 1) & HALF_MASK);
                }
            } else {
                s32 row;

                along = x >> 16;
                row   = (y >> 16) & HALF_MASK;
                sum   = AREA_CELL_BLOCKED(along & HALF_MASK, row);
                sum += AREA_CELL_BLOCKED((along + 1) & HALF_MASK, row);
                if (!(x & HALF_MASK)) {
                    sum += AREA_CELL_BLOCKED((along - 1) & HALF_MASK, row);
                }
            }
            sum += func_801A21EC(x, y);
            sum += func_801A21EC(x + COORD_HALF, y);
            sum += func_801A21EC(x - COORD_HALF, y);
            break;
        case FACING_RIGHT:
            if (x & HALF_MASK) {
                column = ((x >> 16) + 1) & HALF_MASK;
                goto probe_y;
            }
        case FACING_LEFT:
            column = (x >> 16) & HALF_MASK;
        probe_y:
            along = y >> 16;
            sum   = AREA_CELL_BLOCKED(column, along & HALF_MASK);
            sum += AREA_CELL_BLOCKED(column, (along + 1) & HALF_MASK);
            if (!(y & HALF_MASK)) {
                sum += AREA_CELL_BLOCKED(column, (along - 1) & HALF_MASK);
            }
            sum += func_801A21EC(x, y);
            sum += func_801A21EC(x, y + COORD_HALF);
            sum += func_801A21EC(x, y - COORD_HALF);
            break;
        default:
            sum = 1;
            break;
    }
    return sum != 0;
}
#else
INCLUDE_ASM(func_801A1C5C);
#endif

#undef AREA_CELL_BLOCKED
