#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44U))

MATCH void func_801B726C(void) {
    D_801CD2EC[WORK_PTR->unk_03]();
}
