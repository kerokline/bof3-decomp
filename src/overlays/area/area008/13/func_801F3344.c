#include "area008_13.h"

MATCH void func_801F3344(void) {
    Actor* s;
    Actor* e;
    u8     idx;

    s          = g_SpadWork;
    idx        = ((u8*)s)[0x0B];
    e          = &g_Actors[idx];
    g_SpadWork = (Actor*)e;
    if ((g_ScriptVars[3] & 0x80u) != 0u) {
        s->unk_01 = 0x0E;
    } else if (g_ScriptVars[2] == 2) {
        Actor_SelectScript(3);
        s->unk_01 = 3;
    } else if (g_ScriptVars[2] == 5) {
        Actor_SelectScript(3);
        s->unk_01 = 0x0A;
    }
    g_SpadWork = s;
}
