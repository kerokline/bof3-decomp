#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B73B0(void) {
    D_801CD2F4[WORK_PTR->unk_03]();
}
