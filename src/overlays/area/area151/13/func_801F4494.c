#include "area151_13.h"

MATCH void func_801F4494(void) {
    Actor* scratch;
    Actor* work;

    scratch = (Actor*)g_SpadWork;
    if (scratch->unk_0B != 0) {
        if ((scratch->flags_00 & ACTOR_FLAG_OFFSCREEN) != 0) {
            Actor_Clear();
            return;
        }
    } else if ((scratch->flags_00 & ACTOR_FLAG_OFFSCREEN) == 0) {
        scratch->unk_0B = 1;
    }

    work = (Actor*)g_SpadWork;
    work->x.fixed += work->unk_0C;
    work->y.fixed += work->unk_10;
    func_8014D978();
    func_8014D290();
}
