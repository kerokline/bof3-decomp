#include "game_00.h"

MATCH s32 func_8019D20C(s16 map_x, s16 map_y) {
    s32 value                    = Area_GetCellCode(map_x, map_y);
    s32 low                      = value & BYTE_MASK;
    /* FAKE: result pinned to v0; retail keeps the return value live. */
    MATCH_REG(s32, result, "v0") = 0;

    if (low == 0)
        goto end; /* the empty cell is never blocked */
    if (low == 0xC0)
        goto end; /* the 0xC0 class is blocked */
    if ((value & 0xF0) == 0x80)
        goto end; /* the 0x8x class is blocked */
    if ((value & 0xF0) == 0xA0)
        goto end; /* the 0xAx class is blocked */
    result = low != 0x20;
end:
    return result;
}
