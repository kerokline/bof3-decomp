#include "area088_13.h"

MATCH void func_801F438C(void) {
    Actor* scratch;

    scratch = g_SpadWork;
    if (scratch->unk_0B == 0) {
        scratch->unk_09++;
        scratch = g_SpadWork;
        if (scratch->unk_09 >= 0x5A) {
            scratch->unk_0B++;
        }
    }

    if (D_801454F2 != 0 && g_SpadWork->unk_0B != 0) {
        goto bump;
    }
    if (g_GameStateIndex == 2) {
        goto bump;
    }
    if (GAME_SCRIPT_ACTIVE() == 0) {
        goto done;
    }
bump:
    g_SpadWork->unk_03++;
done:
    func_801F4C28(0x5C, g_SpadWork->unk_30);
}
