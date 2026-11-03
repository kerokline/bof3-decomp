#include "game_00.h"

MATCH void func_801BD5A4(void) {
    Actor* work;
    Actor* tail;
    u8*    ids;

    work = g_SpadWork;
    switch (work->state_02) {
        case 0:
            if (D_80145FBB[0].mode != 8) {
                work->unk_01 = 1;
                ACTOR_CLEAR_STATE();
            }
            break;
        case 1:
            g_SpadWork->unk_0B = Actor_FindFreeSlot();
            if (g_SpadWork->unk_0B != GAME_NONE) {
                g_ActorSlots[g_SpadWork->unk_0B].flags_00 = 1;
                g_ActorSlots[g_SpadWork->unk_0B].type     = 6;
                g_ActorSlots[g_SpadWork->unk_0B].unk_06   = 1;
                tail                                      = g_SpadWork;
                ids                                       = (u8*)g_GameState;
                g_ActorSlots[tail->unk_0B].step_0C        = 0;
                g_ActorSlots[tail->unk_0B].selection_10   = D_80181B28[ids[0x79]];
                g_ActorSlots[tail->unk_0B].unk_2E         = tail->unk_2E;
                g_ActorSlots[tail->unk_0B].unk_30         = tail->unk_30;
                tail->state_02                            = 2;
            } else {
                ACTOR_CLEAR_STATE();
            }
            break;
        case 2:
            if (g_ActorSlots[g_SpadWork->unk_0B].flags_00 == 0) {
                ACTOR_CLEAR_STATE();
            }
            break;
    }
    func_8014D978();
}
