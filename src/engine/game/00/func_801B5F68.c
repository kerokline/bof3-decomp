#include "game_00.h"

MATCH bool func_801B5F68(s32 selection_kind) {
    s32 kind;
    s8  result;

    kind = g_GameState->slot_index_79;
    if (kind != 3 && kind != 6)
        return false;
    if (!(g_SpadWork->direction_08 & 1))
        return false;
    if ((selection_kind & BYTE_MASK) != 4)
        return false;
    result = func_801B5AE4(selection_kind, kind);
    if (result == -1)
        return false;
    g_GameState->mode_12B.u8_value = 8;
    g_SpadWork->unk_0B             = (u8)result;
    g_SpadWork->unk_01             = 0x0A;
    g_SpadWork->state_02           = 1;
    g_SpadWork->unk_03             = 0;
    return true;
}
