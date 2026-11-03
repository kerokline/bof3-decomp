#include "game_00.h"

/* func_801960C0 */
MATCH void Actor_Free(u8 record_index) {
    g_ActorSlots[record_index].flags_00 = 0;
    g_ActorSlots[record_index].unk_01   = 0;
    g_ActorSlots[record_index].unk_02   = 0;
    g_ActorSlots[record_index].unk_03   = 0;
    g_ActorSlots[record_index].unk_04   = 0;
}
