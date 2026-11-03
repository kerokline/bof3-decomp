#include "sisyou_00.h"

/* Shared state step owned by the main executable. */

/* Work-entry stock list, its selector, and the per-entry stock table. */

/* func_801D3ED0 */
MATCH void Master_ApplyMaster(void) {
    u8 value;

    if (g_GameStateIndex == GAME_REQUEST_MESSAGE) {
        return;
    }
    value = D_801D4270[D_801448ED];
    if (value != GAME_NONE) {
        D_80146889[D_80146867 * ACTOR_SIZE] = value;
    }
    g_MasterStep = 0;
    D_801448EC++;
}
