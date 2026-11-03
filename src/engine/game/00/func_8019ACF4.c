#include "game_00.h"

MATCH void func_8019ACF4(void) {
    Actor* work;
    s32    pos;
    s32    step;

    func_8019AA44();
    work              = (Actor*)SCRATCH_WORK;
    pos               = (g_AreaViewOffsetZ << 16) + work->unk_10;
    /* FAKE: volatile re-read keeps the direction load before the store.
     */
    step              = FIELD(volatile s32, work, 0x10u);
    g_AreaViewOffsetZ = (s16)(pos >> 16);
    if (step < 0) {
        if (g_AreaViewOffsetZ < work->unk_0C) {
            g_AreaViewOffsetZ = (s16)work->unk_0C;
        }
    } else {
        if (g_AreaViewOffsetZ > work->unk_0C) {
            g_AreaViewOffsetZ = (s16)work->unk_0C;
        }
    }
}
