#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B3400(void) {
    if (func_801C4F88() & BYTE_MASK) {
        WORK_PTR->unk_03 = 4;
    }
}
