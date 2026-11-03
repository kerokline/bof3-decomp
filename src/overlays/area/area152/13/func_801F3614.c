#include "area152_13.h"

MATCH void func_801F3614(void) {
    Actor* scratch;

    scratch = g_SpadWork;
    scratch->unk_30 -= 0xA;
    if (scratch->unk_30 < 0xC9) {
        scratch->unk_03++;
    }

    if (D_801454F2 != 0 && ((u8*)g_SpadWork)[0xB] != 0) {
        goto force;
    }
    if (g_GameStateIndex == 2) {
        goto force;
    }
    if (GAME_SCRIPT_ACTIVE() == 0) {
        goto done;
    }
force:
    ((u8*)g_SpadWork)[3] = 3;
done:
    func_801F3F88(0x5C, g_SpadWork->unk_30);
}
