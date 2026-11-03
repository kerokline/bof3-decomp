#include "start_08.h"

MATCH s32 func_801D2190(void) {
    u8 value;
    u8 code;
    /* FAKE: result pinned to v0; retail keeps the return value live. */
    MATCH_REG(s32, result, "v0");

    value  = Area_GetCellCode(D_80145EC6, D_80145ECA);
    code   = value & 0xF0;
    result = 0;
    if ((u32)(u8)(code + 0x60) < 2U) {
        /* Class 0 and 0xC0 rows are walkable. */
        goto end;
    }
    if (code == 0xAF) {
        /* The 0xAF code is walkable. */
        goto end;
    }
    result = code != 0x91;
end:
    return result;
}
