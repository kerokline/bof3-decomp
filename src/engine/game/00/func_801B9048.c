#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B9048(void) {
    g_GameState->mode_12B.u8_value = 6;
    D_801CD374[WORK_PTR->unk_03]();
}
