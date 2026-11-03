#include "area008_13.h"

MATCH void func_801F3344(void) {
    Actor* s;
    Actor* e;
    u8     idx;

    s          = g_SpadWork;
    idx        = ((u8*)s)[0x0B];
    e          = &g_Actors[idx];
    g_SpadWork = (Actor*)e;
    if ((WORLD00_AREA008_D_80146867 & 0x80u) != 0u) {
        s->unk_01 = 0x0E;
    } else if (D_80146866 == 2) {
        Actor_SelectScript(3);
        s->unk_01 = 3;
    } else if (D_80146866 == 5) {
        Actor_SelectScript(3);
        s->unk_01 = 0x0A;
    }
    g_SpadWork = s;
}
