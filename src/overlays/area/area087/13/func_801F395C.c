#include "area087_13.h"

MATCH void func_801F395C(void) {
    Actor* scratch;
    /* FAKE: value pinned to v0. */
    MATCH_REG(s32, armed, "v0");

    scratch = g_SpadWork;
    scratch->unk_30 += 0xA;
    if (scratch->unk_30 >= 0xF0) {
        scratch->unk_03 = 0;
    }
    if (D_801454F2 == 0 && g_GameStateIndex != 2 && GAME_SCRIPT_ACTIVE() == 0) {
        armed              = 1;
        g_SpadWork->unk_03 = armed;
    }
    func_801F40F8(0x5C, g_SpadWork->unk_30);
}
