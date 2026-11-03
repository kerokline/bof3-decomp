#include "game_00.h"

MATCH s32 func_801AFD10(u8* column_counter, u8* row_offset, u8* row_flag, u8* position) {
    u8 state;
    u8 hi;
    u8 lo;
    u8 ret;

    state = *position;
    lo    = state & 0xF;
    hi    = state >> 4;
    if (hi == 1) {
        if (lo == 0) {
            *column_counter = *column_counter + 1;
        }
        lo = (lo + 4) % 12;
        if (lo == 0) {
            hi          = 0;
            *row_offset = 0;
            *row_flag   = 0;
            ret         = *column_counter;
        } else {
            *row_offset = -lo;
            *row_flag   = 1;
            ret         = *column_counter - 1;
        }
    } else if (hi == 0xF) {
        if (lo == 0) {
            *column_counter = *column_counter - 1;
            lo              = 8;
        } else {
            lo = lo - 4;
        }
        if (lo == 0) {
            hi          = 0;
            *row_offset = 0;
            *row_flag   = 0;
        } else {
            *row_offset = -lo;
            *row_flag   = 1;
        }
        ret = *column_counter;
    } else {
        *row_offset = 0;
        *row_flag   = 0;
        ret         = *column_counter;
    }
    *position = lo + (hi << 4);
    return ret;
}
