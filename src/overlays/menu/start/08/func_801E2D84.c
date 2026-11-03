#include "start_08.h"

extern void func_801E2E90(s32 x, s32 y, s32 row_index);

MATCH void func_801E2D84(s16 x, s32 y) {
    u8   data[6];
    u16* flag_table;
    s32  row_y;
    s32  i;

    memcpy(data, D_801D0E20, sizeof(data));
    Menu_DrawWindowFrame((s16)x, (s16)y, 0xC, 0xF);
    i          = 0;
    row_y      = y + 6;
    flag_table = &g_InputMasks;
    do {
        u8  cell;
        s32 cell_y;

        cell   = (u8)i;
        cell_y = (row_y + cell * 0x12) & HALF_MASK;
        func_801E2E90((u16)(x + 5), (u16)cell_y, cell);
        func_801E30FC((u16)(x + 0x44), (u16)cell_y, flag_table[data[cell]]);
        i += 1;
    } while ((u32)(i & BYTE_MASK) < 6U);
}
