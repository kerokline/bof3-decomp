#include "game_00.h"

/* func_801A4BC0 */
MATCH void Area_SetCellCode(s16 column, s16 row, u8 code) {
    *(u8*)(g_AreaCellCodes + row * D_80104000 + column) = code;
}
