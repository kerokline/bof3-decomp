#include "area121_14.h"

MATCH void func_801F3768(void) {
    Actor* work;
    s16    origin_y;

    work         = g_SpadWork;
    origin_y     = work->unk_30 - 0xA;
    work->unk_30 = origin_y;
    if (origin_y < 201) {
        work->unk_03++;
    }

    if (D_801454F2 != 0 && g_SpadWork->unk_0B != 0) {
        goto force; /* skips the 0x100 test: force state byte 3 */
    }
    if (g_GameStateIndex == GAME_REQUEST_MESSAGE) {
        goto force; /* skips the 0x100 test: force state byte 3 */
    }
    if (GAME_SCRIPT_ACTIVE() == 0) {
        goto done; /* skips the forced write: panel 0x5C draws next */
    }
force:
    g_SpadWork->unk_03 = 3;
done:
    func_801F40DC(0x5C, g_SpadWork->unk_30);
}
