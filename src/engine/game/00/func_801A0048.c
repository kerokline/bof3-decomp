#include "game_00.h"

/* Finds the area link at a map cell and makes its destination the pending area change; true when none. */
MATCH bool func_801A0048(s32 cell_x, s32 cell_y) {
    GameLocale*     link;
    u8*             choice;
    s32             n;
    s32             i;
    s32             count;
    GameLocaleBank* bank;
    u32             x;
    u32             y;

    n = ((GameLocaleBank**)g_AreaLoads)[g_GameAreaId]->outer;
    for (; n >= 0; n--) {
        link = &((GameLocaleBank**)g_AreaLoads)[g_GameAreaId]->entries[n];
        for (i = link->span - 1; i >= 0; i--) {
            if (link->mode != 0) {
                if ((cell_x & BYTE_MASK) == link->cx && (cell_y & BYTE_MASK) == link->cy + i) {
                    goto found;
                }
            } else if ((cell_x & BYTE_MASK) == link->cx + i && (cell_y & BYTE_MASK) == link->cy) {
                goto found;
            }
            continue;
        found:
            if (link->key == 0xFFFF) {
                bank   = ((GameLocaleBank**)g_AreaLoads)[g_GameAreaId];
                choice = (u8*)bank->keys[link->index];
                count  = bank->counts[link->index];
                for (n = 0; n < count; n++, choice += 10) {
                    if (SYS_TestFlag(g_SceneFlagWords + choice[6] * 8, choice[7]) != 0) {
                        break;
                    }
                }
                x                 = *(u16*)(choice + 2);
                g_GameEntryAreaId = *(u16*)choice;
                y                 = *(u16*)(choice + 4);
                g_GameEntryPosX   = (x << 8) & 0xFF8000;
                g_GameEntryPosY   = (y << 8) & 0xFF8000;
                g_GameEntryFacing = choice[8];
            } else {
                g_GameEntryAreaId = link->key;
                g_GameEntryPosX   = (link->index << 8) & 0xFF8000;
                g_GameEntryPosY   = (link->alt << 8) & 0xFF8000;
                g_GameEntryFacing = link->type;
            }
            g_ScratchPad.cells.bytes[1] = (g_GameEntryFacing >> 4) & 7;
            g_GameEntryFacing &= 0x8F;
            func_801A02E8();
            func_801A0380(D_80143F16, D_80143F1A, g_GameEntryAreaId);
            return false;
        }
    }
    return true;
}
