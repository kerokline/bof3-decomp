#include "area149_13.h"

/* The area scroll target as the one record retail reads it as: each read stays behind the store before it. */
typedef struct {
    s32 x;
    s32 y;
} AreaScrollTarget;

/* Every fourth frame, two spawned actors of type 0x37 one unit either side of the scroll target. */
MATCH void func_801F3140(s8 span) {
    u8  slot;
    u8  i;
    s32 y;

    if ((g_FrameCount & 3) != 0) {
        return;
    }

    for (i = 0; i < 2; i++) {
        slot = Actor_FindFreeSpawned();
        if (slot != 0xFF) {
            g_SpawnedActors[slot].header.flags     = ACTOR_FLAG_IN_USE;
            g_SpawnedActors[slot].type             = 0x37;
            g_SpawnedActors[slot].unk_2C           = 0x2C0;
            g_SpawnedActors[slot].pos.x.fixed      = ((AreaScrollTarget*)&g_AreaScrollTargetX)->x + TO_COORD(span);
            y                                      = ((AreaScrollTarget*)&g_AreaScrollTargetX)->y;
            g_SpawnedActors[slot].pos.y.fixed      = y + (i != 0 ? -TO_COORD(1) : TO_COORD(1));
            COORD_INT(g_SpawnedActors[slot].pos.z) = Area_HeightSample(g_SpawnedActors[slot].pos.x.fixed, g_SpawnedActors[slot].pos.y.fixed);
            g_SpawnedActors[slot].unk_2C           = 0x2C0;
            g_SpawnedActors[slot].layer            = 1;
            g_SpawnedActors[slot].unk_06           = 0;
            g_SpawnedActors[slot].unk_07           = 0;
            g_SpawnedActors[slot].unk_29           = 6;
        }
    }
}
