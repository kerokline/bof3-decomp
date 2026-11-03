#include "area098_13.h"

MATCH void func_801F3E64(void) {
    Actor* work;

    func_801F4D44();
    work         = g_SpadWork;
    work->unk_2E = 0x40;
    work->unk_30 = 0;
    work->unk_01++;
    SND_PlayCue(0x200);
}
