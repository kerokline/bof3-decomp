#include "game_00.h"

MATCH void func_801AF800(s16 record_x, s32 record_y, u8 record_kind, u8 record_mode, s32 record_index, s32 record_shade,
                         s32 sprite_flag) {
    s16   x;
    s32   row;
    u8    mode;
    u32   shade;
    u8    flag;
    u8*   entry;
    u8    index;
    u8    kind;
    u8    shade_byte;
    u8    table_index;
    char* buffer;
    u16   ux;

    index       = (u8)record_index;
    shade_byte  = (u8)record_shade;
    x           = record_x;
    mode        = record_mode;
    flag        = (u8)sprite_flag;
    kind        = record_kind;
    table_index = (u8)Item_GetKind(mode, (s32)index);
    row         = record_y + 2;
    ux          = (u16)x;
    func_801AEA80((s32)ux, row & HALF_MASK, (s32)s_ItemSpriteIds[table_index], (s32)flag);
    entry = Item_GetRecord(mode, (s32)index);
    kind &= BYTE_MASK;
    UI_DrawText(x + 10, record_y, (s32)kind, func_801AF20C(entry) & BYTE_MASK, entry);
    shade = shade_byte & BYTE_MASK;
    if (shade >= 2U) {
        buffer = (char*)g_UiFormatBuffer;
        sprintf(buffer, D_80195F90, shade);
        UI_DrawGlyphString((s16)(x + 109), row, (u32)kind, (const u8*)buffer);
    }
}
