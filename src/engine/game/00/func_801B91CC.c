#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B91CC(void) {
    D_801CD37C[WORK_PTR->unk_03]();
}
