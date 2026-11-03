#include "area104_14.h"

/* func_801F2F0C */
MATCH void Message_RunAreaMessage(void) {
    s8* state;

    state = &D_801448EC;
    switch (*state) {
        case 0:
            Game_SetScriptActive();
            Message_StartAreaMessage(4);
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
