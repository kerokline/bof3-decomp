#include "battle_03.h"

MATCH void func_801E347C(void) {
    PartyBattler* work;
    s32           old38;
    s32           old34;

    work = g_SpadWork;
    work->flags_00 &= ~ACTOR_FLAG_HIDDEN;
    func_801E2314(0);
    old34              = g_SpadWork->coord_x_34.raw;
    old38              = g_SpadWork->coord_y_38.raw;
    g_SpadWork->unk_0C = 0x80000;
    g_SpadWork->unk_10 = 0;
    g_SpadWork->unk_18 = old34;
    work               = g_SpadWork;
    work->unk_1C       = old38;
    func_801DD350((s32)work);
    {
        s32 dx;
        s32 dy;
        s32 depth;

        depth              = g_SpadWork->coord_x_34.raw;
        dx                 = g_SpadWork->unk_0C;
        dy                 = g_SpadWork->unk_10;
        g_SpadWork->unk_0C = 0x8000;
        g_SpadWork->unk_10 = 0;
        depth -= dx;
        ((volatile PartyBattler*)g_SpadWork)->coord_x_34.raw = depth;
        depth -= dy;
        work                 = g_SpadWork;
        work->coord_x_34.raw = depth;
        func_801DD350((s32)work);
    }
    work         = g_SpadWork;
    work->unk_02 = work->unk_02 + 1;
}
