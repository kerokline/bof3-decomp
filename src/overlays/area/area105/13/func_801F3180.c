#include "area105_13.h"

MATCH void func_801F3180(void) {
    s8* state;

    state = &D_801448EC;
    switch (*state) {
        case 0:
            Message_StartAreaMessage(1);
            g_GameStateIndex = GAME_REQUEST_MESSAGE;
            *state           = 1;
            return;
        case 1:
            if (g_GameStateIndex != GAME_REQUEST_MESSAGE) {
                Game_ClearScriptActive();
                D_801448EB = 0;
                *state     = 0;
            }
            return;
    }
}
