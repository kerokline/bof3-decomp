#include "area098_13.h"

MATCH void func_801F4F60(Actor* actor) {
    u8 state;

    actor->unk_03 += 0x10;
    state           = actor->state_02 - 1;
    actor->state_02 = state;
    if (state == 0) {
        actor->state_02 = actor->unk_04;
        actor->unk_01++;
        if (D_801F6510 == 0) {
            D_801F6510 = 1;
        }
    }
}
