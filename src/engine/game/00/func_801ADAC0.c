#include "game_00.h"

/* The slot scanner is entered with a0 still holding the caller's argument, so
 * it is reached through a K&R declaration rather than its typed prototype. */

MATCH void func_801ADAC0(s8 slot_index) {
    s8 value;

    g_SpadWork->unk_0B = Actor_FindFreeSlot();
    if (g_SpadWork->unk_0B != GAME_NONE) {
        g_ActorSlots[g_SpadWork->unk_0B].flags_00     = 1;
        g_ActorSlots[g_SpadWork->unk_0B].type         = 0x19;
        g_ActorSlots[g_SpadWork->unk_0B].unk_06       = slot_index;
        g_ActorSlots[g_SpadWork->unk_0B].step_0C      = 0;
        value                                         = func_801ADC98();
        g_ActorSlots[g_SpadWork->unk_0B].selection_10 = value + 0x28;
        g_ActorSlots[g_SpadWork->unk_0B].x.fixed      = g_SpadWork->x.fixed;
        g_ActorSlots[g_SpadWork->unk_0B].y.fixed      = g_SpadWork->y.fixed;
        g_ActorSlots[g_SpadWork->unk_0B].z.fixed      = g_SpadWork->z.fixed;
    }
}
