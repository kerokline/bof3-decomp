#include "area115_13.h"

MATCH void func_801F392C(void) {
    Actor* work;
    s16    origin_y;

    work         = g_SpadWork;
    origin_y     = work->unk_30 + 0xA;
    work->unk_30 = origin_y;
    if (origin_y >= 240) {
        work->unk_03 = 0;
    }

    if (D_801454F2 == 0 && g_GameStateIndex != 2 && GAME_SCRIPT_ACTIVE() == 0) {
        work         = g_SpadWork;
        work->unk_03 = 1;
    }

    func_801F40C8(0x5C, g_SpadWork->unk_30);
}
