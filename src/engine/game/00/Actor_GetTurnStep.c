#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH s32 Actor_GetTurnStep(s32 selector) {
    s32 field;
    s32 value;

    field = WORK_PTR->direction_08;
    selector &= BYTE_MASK;
    value = field & BYTE_MASK;
    if ((u32)field < (u32)selector) {
        field += 8;
        value = field & BYTE_MASK;
    }
    if ((value >= selector + 1) && (selector + 4 >= value)) {
        return -1;
    }
    return 1;
}
