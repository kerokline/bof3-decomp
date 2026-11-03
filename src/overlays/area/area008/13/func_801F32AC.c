#include "area008_13.h"

MATCH void func_801F32AC(void) {
    Actor* e;
    u8     idx;

    if ((WORLD00_AREA008_D_80146867 & 0x80u) != 0u) {
        g_SpadWork->unk_01 = 0x0E;
        return;
    }
    if (D_80146866 == 1) {
        idx = ((u8*)g_SpadWork)[0x0B];
        e   = &g_Actors[idx];
        e->flags_00 &= ~ACTOR_FLAG_HIDDEN;
        g_SpadWork->unk_01 = 2;
    }
}
