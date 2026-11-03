#include "area033_13.h"

MATCH void func_801F3294(void) {
    u8*  scratch;
    u8*  check;
    u8** slots;

    Actor_CenterOnScreen();

    slots   = SP_PTR(u8*, 0u);
    scratch = slots[0x11];
    scratch[0x09] -= 1;

    slots = SP_PTR(u8*, 0u);
    check = slots[0x11];
    *(s32*)(scratch + 0x40) -= 0x2000;

    if (check[0x09] == 0) {
        if (g_GameStateIndex == GAME_REQUEST_AREA_CHANGE) {
            Actor_Clear();
            return;
        }
        check[0x48]              = 0;
        SP_PTR(u8*, 0u)[0x11][1] = 1;
        return;
    }

    Area_AddActor();
}
