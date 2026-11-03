#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH void func_801B78B4(void) {
    g_GameState->mode_12B.u8_value = 3;
    D_801CD308[WORK_PTR->unk_03]();
}
