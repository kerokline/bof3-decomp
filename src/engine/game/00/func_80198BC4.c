#include "game_00.h"

MATCH void func_80198BC4(u32 wait_steps) {
    u8 force_update;

    force_update = wait_steps;
    while (1) {
        CallbackWait(1);
        if (WINDOW_EFFECT_IDLE() && force_update == 0) {
            CallbackWait(1);
            break;
        }
        Area_RunFrame();
        if (WINDOW_EFFECT_IDLE()) {
            break;
        }
    }
}
