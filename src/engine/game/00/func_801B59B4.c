#include "game_00.h"

/* Plain scratchpad cell read; emits a fresh absolute load per use. */
#define WORK_PTR (*SP_PTR(Actor*, 0x44u))

MATCH s32 func_801B59B4(void) {
    s32 kind;

    kind = D_8014625C & INPUT_DIRECTIONAL;
    switch (kind) {
        case PADLup:
            WORK_PTR->direction_08 = 0;
            break;
        case PADLup | PADLright:
            WORK_PTR->direction_08 = 1;
            break;
        case PADLright:
            WORK_PTR->direction_08 = 2;
            break;
        case PADLright | PADLdown:
            WORK_PTR->direction_08 = 3;
            break;
        case PADLdown:
            WORK_PTR->direction_08 = 4;
            break;
        case PADLdown | PADLleft:
            WORK_PTR->direction_08 = 5;
            break;
        case PADLleft:
            WORK_PTR->direction_08 = 6;
            break;
        case PADLleft | PADLup:
            WORK_PTR->direction_08 = 7;
            break;
        default:
            return 0;
    }
    return 1;
}
