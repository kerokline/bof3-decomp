#include "area033_13.h"

MATCH void func_801F40F0(void) {
    s32  i;
    s16  count;
    s32  roll;
    u8   kind;
    u8   index;
    s16  distance;
    /* FAKE: address-taken 8-byte local reserves retail's unused vars
     * slot; the pointer itself is never dereferenced. */
    s32  coords[2];
    s32* cp;

    if (D_80146871 & 1) {
        Actor_Clear();
        return;
    }
    if (g_FrameCount & 0x3FF) {
        return;
    }
    i     = 0;
    cp    = coords;
    roll  = rand();
    count = roll & 3;
    /* FAKE: keep the shift inside the loop body so loop.c hoists it as a loop
     * invariant; the hoist lands after the hoisted `1` (retail `li s3,1` in the
     * blez delay slot at 0x68/0x6c, `srl s5,v1,4` at 0x70). */
    kind  = (u8)(roll & 0x33);
    if (count <= 0) {
        return;
    }
    do {
        index = Actor_FindFreeSlot();
        if (index == GAME_NONE) {
            break;
        }
        g_ActorSlots[index].flags_00       = 1;
        g_ActorSlots[index].type           = 0x16;
        g_ActorSlots[index].unk_01         = 1;
        g_ActorSlots[index].unk_06         = (u8)i;
        g_ActorSlots[index].unk_08         = (u8)(kind >> 4);
        distance                           = Area_SampleHeight(D_80145EC4[0], D_80145EC4[1]) + 0x400;
        g_ActorSlots[index].z.part.integer = distance;
        i++;
    } while (i < count);
}
