#include "area104_14.h"

MATCH void func_801F38EC(void) {
    if (g_SpadWork->unk_0B == 0) {
        g_SpadWork->unk_09++;
        if (g_SpadWork->unk_09 >= 0x5A) {
            g_SpadWork->unk_0B++;
        }
    }

    if (D_801454F2 != 0 && g_SpadWork->unk_0B != 0) {
        goto bump; /* skips the 0x100 test: advance state byte 0x03 */
    }
    if (g_GameStateIndex == 2) {
        goto bump; /* skips the 0x100 test: advance state byte 0x03 */
    }
    if (GAME_SCRIPT_ACTIVE() == 0) {
        goto done; /* skips the advance: panel `0x5C` draws next */
    }
bump:
    g_SpadWork->unk_03++;
done:
    func_801F4188(0x5C, g_SpadWork->unk_30);
}
