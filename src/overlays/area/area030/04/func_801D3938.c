#include "area030_04.h"

/* Advances the local scratch vertical offset and routes the next
 * AREA030 panel draw through the later helper at `0x801D9534`. */
/* FAKE: retail reads and writes the screen y as an unsigned halfword. */
MATCH void func_801D3938(void) {
    s32 val;

    val                        = *(u16*)&g_SpadWork->unk_30 - 8;
    *(u16*)&g_SpadWork->unk_30 = (u16)val;

    if ((s16)val < -0x19) {
        if (FISHING_STATE->counter_07 != 0u) {
            FISHING_STATE->handler_index_01 = 1u;
        } else {
            FISHING_STATE->handler_index_01 = 0u;
        }
    }

    func_801D9534(0x14, *(u16*)&g_SpadWork->unk_30, 0x118, 0x13, 0);
}
