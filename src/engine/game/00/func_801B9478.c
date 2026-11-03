#include "game_00.h"

MATCH void func_801B9478(void) {
    Actor* work;
    Actor* flag_work;
    u8     countdown;

    if (g_SpadWork->unk_09 != 0) {
        func_801C57B4();
        work         = g_SpadWork;
        work->unk_09 = (u8)(work->unk_09 - 1);
        if (g_SpadWork->unk_09 == 0) {
            Actor_ClearVelocity();
        }
    }
    work      = g_SpadWork;
    countdown = work->unk_0A;
    if (countdown != 0) {
        work->unk_0A = (u8)(countdown - 1);
        flag_work    = g_SpadWork;
        if (flag_work->unk_0A & 1) {
            flag_work->flags_00 = (u8)(flag_work->flags_00 & ~ACTOR_FLAG_HIDDEN);
            return;
        }
        flag_work->flags_00 = (u8)(flag_work->flags_00 | ACTOR_FLAG_HIDDEN);
        return;
    }
    work->flags_00       = (u8)(work->flags_00 & ~ACTOR_FLAG_HIDDEN);
    g_SpadWork->unk_01   = 1;
    g_SpadWork->state_02 = 0;
    g_SpadWork->unk_03   = 0;
}
