#include "area008_13.h"

MATCH void func_801F37BC(void) {
    Actor* s;
    Actor* e;
    u8     idx;

    s          = g_SpadWork;
    idx        = ((u8*)s)[0x0B];
    e          = &g_Actors[idx];
    g_SpadWork = (Actor*)e;
    if ((WORLD00_AREA008_D_80146867 & 0x80u) != 0u) {
        s->unk_01 = 0x0E;
    } else if ((e->unk_58 == 8) && (e->unk_4A == 1)) {
        Actor_SelectScript(4);
        s->unk_01 = 0x0B;
    }
    g_SpadWork = s;
}
