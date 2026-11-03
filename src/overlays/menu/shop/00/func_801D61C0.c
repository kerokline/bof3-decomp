#include "shop_00.h"

/* File-local declarations: frontend flag word, party-size byte, party pointer
 * table, and helpers owned by this target or the executable overlay. */

MATCH void func_801D61C0(void) {
    s16 value;
    s16 i;
    s16 next;

    if (SYS_TestFlag(g_SceneEventFlags, 0x77) != 0) {
        D_80148651 = 6;
        Message_StartAreaMessage(0xEF);
        return;
    }
    if (g_SceneState.scenario_id != 0xE || SYS_TestFlag(*g_SceneFlags, 5) == 0) {
        SYS_SetFlag(g_SceneEventFlags, 0x77);
    }
    i = 0;
    do {
        value         = SsIsEos(0, i);
        D_801E6100[i] = value;
        if (value != 0) {
            SsSepPause(0, i);
            /* Empty loop: the retail tail keeps the next-value increment in
             * the cue call's delay slot; the block boundary holds it. */
            do {
            } while (0);
        }
        next = i + 1;
        i    = next;
    } while (next < 4);
    UI_SetMode(0);
    {
        u8* state;

        state = &D_80148651;
        *state += 1;
    }
}
