#include "battle_15.h"

MATCH void func_800AD434(void) {
    PartyBattler* work;
    Callback      funcs[2] = {func_800AD4D4, func_800AD5C8};
    u8            two;

    work = (PartyBattler*)g_SpadWork;
    funcs[work->unk_02]();
    two = 2u;
    if (!(D_80148624 & 1)) {
        BATTLE_WORK->step_01 = two;
        BATTLE_WORK->unk_02  = 0;
        return;
    }
    func_8014D978();
    Area_AddActor();
}
