#include "battle_15.h"

/* func_800ACFF4 */
MATCH void Actor_Clear(void) {
    BATTLE_WORK->flags_00 = 0;
    BATTLE_WORK->step_01  = 0;
    BATTLE_WORK->unk_02   = 0;
    BATTLE_WORK->unk_03   = 0;
    BATTLE_WORK->unk_04   = 0;
}
