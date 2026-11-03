#include "area115_13.h"

MATCH void func_801F382C(void) {
    Actor* work;

    work = g_SpadWork;
    if (work->unk_0B == 0) {
        work->unk_09++;
        work = g_SpadWork;
        if (work->unk_09 >= 0x5A) {
            work->unk_0B++;
        }
    }

    if (D_801454F2 != 0 && g_SpadWork->unk_0B != 0) {
        goto bump; /* skips the 0x100 test: advance state byte 3 */
    }
    if (g_GameStateIndex == GAME_REQUEST_MESSAGE) {
        goto bump; /* skips the 0x100 test: advance state byte 3 */
    }
    if (GAME_SCRIPT_ACTIVE() == 0) {
        goto done; /* skips the advance: panel 0x5C draws next */
    }
bump:
    g_SpadWork->unk_03++;
done:
    func_801F40C8(0x5C, g_SpadWork->unk_30);
}
