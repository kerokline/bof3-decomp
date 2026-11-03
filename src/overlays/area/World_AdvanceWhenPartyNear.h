#ifndef WORLD_ADVANCE_WHEN_PARTY_NEAR_H
#define WORLD_ADVANCE_WHEN_PARTY_NEAR_H

#include "work/area_spad.h"

/* Advance the work state when the party position is inside the work cell. */
static inline void World_AdvanceWhenPartyNear(void) {
    if (g_SpadWork->direction_08 != 0) {
        if (abs(D_80145EC8 - ((((s32)g_SpadWork->y.part.integer + 1) << 16) | 0x8000)) <= 0x8000) {
            if (abs(D_80145EC4 - ((s32)g_SpadWork->x.part.integer << 16)) <= 0x10000 ||
                abs(D_80145EC4 - (((s32)g_SpadWork->x.part.integer + 1) << 16)) <= 0x10000) {
                if (D_80143BB0 == 0) {
                    SND_PlayCue(EMI_CUE_ID(2, 0));
                }
                g_SpadWork->state_02++;
            }
        }
    } else {
        if (abs(D_80145EC4 - ((((s32)g_SpadWork->x.part.integer + 1) << 16) | 0x8000)) <= 0x8000) {
            if (abs(D_80145EC8 - ((s32)g_SpadWork->y.part.integer << 16)) <= 0x10000 ||
                abs(D_80145EC8 - (((s32)g_SpadWork->y.part.integer + 1) << 16)) <= 0x10000) {
                if (D_80143BB0 == 0) {
                    SND_PlayCue(EMI_CUE_ID(2, 0));
                }
                g_SpadWork->state_02++;
            }
        }
    }
}

#endif
