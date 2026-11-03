#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_8019A53C(void) {
    D_801C80A4[WORK_PTR->unk_06]();
}
