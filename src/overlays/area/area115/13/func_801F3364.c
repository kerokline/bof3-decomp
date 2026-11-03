#include "area115_13.h"

MATCH void func_801F3364(void) {
    u8* work;
    u8* check;

    Actor_CenterOnScreen();

    work = (u8*)g_SpadWork;
    work[9] -= 1;
    check = (u8*)g_SpadWork;
    FIELD(s32, work, 0x40) -= 0x2000;

    if (check[9] == 0) {
        if (g_GameStateIndex == GAME_REQUEST_AREA_CHANGE) {
            Actor_Clear();
            return;
        }
        check[0x48]        = 0;
        g_SpadWork->unk_01 = 1;
        return;
    }

    Area_AddActor();
}
