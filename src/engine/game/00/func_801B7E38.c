#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B7E38(void) {
    if (func_801C4FE0() & BYTE_MASK) {
        WORK_PTR->unk_04 = 5;
    }
}
