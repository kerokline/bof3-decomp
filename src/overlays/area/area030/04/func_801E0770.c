#include "area030_04.h"

/* Reports whether the area030 anchor may settle: graphics mode 4 with
 * an exhausted sprite bank, no pending flag and area state 3, then the
 * scratchpad probe record within 0x7FFF of the anchor on x and y and within
 * 0x400 on z. */
MATCH s32 func_801E0770(void) {
    u8* spad;
    s32 d;
    /* FAKE: retail keeps the z delta in $v0. */
    MATCH_REG(s32, dz, "v0");
    /* FAKE: retail keeps the y anchor in $a0. */
    MATCH_REG(s32, anchor, "a0");
    s32 limit;
    /* FAKE: retail holds the failure status in $v0 across the guard chain. */
    MATCH_REG(s32, result, "v0");

    result = 0;
    if (4 != g_ActorSlots[0].unk_01) {
        return result;
    }
    if (0xFF != D_801E3208) {
        return result;
    }
    if (0 != D_80144199) {
        return result;
    }
    limit = 0x7FFF;
    if (3 != D_80145E92[0]) {
        return result;
    }
    spad = (u8*)g_SpadWork;
    d    = -g_ActorSlots[0].x.fixed + *(s32*)(spad + 0x34);
    if (d < 0) {
        d = -d;
    }
    if (d > 0x7FFF) {
        return result;
    }
    d      = *(s32*)(spad + 0x38);
    anchor = g_ActorSlots[0].y.fixed;
    d      = d - anchor;
    if (d < 0) {
        d = -d;
    }
    if (d > limit) {
        return result;
    }
    dz = *(s16*)(spad + 0x3E);
    dz = dz - g_ActorSlots[0].z.part.integer;
    if (dz < 0) {
        dz = -dz;
    }
    return dz < 0x400;
}
