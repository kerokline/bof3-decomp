#include "game_00.h"

MATCH u8* func_801A42F0(u8* cursor, s8* flag, u8* counter) {
    u8 value;

    value = *cursor;
    if (value >= 0xF0) {
        if (value < 0xFD) {
            cursor = func_801A4400(cursor);
        } else if (value == 0xFE) {
            *counter -= 1;
        } else {
            if (value == 0xFD) {
                *flag = 1;
            }
            cursor += 1;
        }
    } else {
        cursor = func_801A4BF8(cursor);
    }
    return cursor;
}
