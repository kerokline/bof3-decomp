#include "game_00.h"

/* Scratchpad work pointer: weak symbol emits lui+lw per use. */
/* K&R call forwards a0 untouched as the mode argument. */

MATCH void func_801ADCF4(u8 slot_index) {
    g_SpadWork->unk_0B = Actor_FindFreeSlot();
    if (g_SpadWork->unk_0B != GAME_NONE) {
        g_ActorSlots[g_SpadWork->unk_0B].flags_00 = 1;
        g_ActorSlots[g_SpadWork->unk_0B].type     = 0x32;
        g_ActorSlots[g_SpadWork->unk_0B].unk_06   = slot_index;
    }
}
