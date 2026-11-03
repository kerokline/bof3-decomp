#include "game_00.h"

/* func_801A82F8 */
MATCH void Message_RunAreaMessage(void) {
    s8* state;

    state = &D_801448EC;
    switch (*state) {
        case 0:
            Game_SetScriptActive();
            Message_StartAreaMessage(0xD8);
            g_GameStateIndex = 2;
            *state           = (u8)*state + 1;
            return;
        case 1:
            if (g_GameStateIndex != 2) {
                Game_ClearScriptActive();
                D_801448EB = 0;
                *state     = 0;
                D_801448ED = 0;
            }
            return;
    }
}
