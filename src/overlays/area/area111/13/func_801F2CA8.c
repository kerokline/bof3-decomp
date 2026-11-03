#include "area111_13.h"

MATCH void func_801F2CA8(void) {
    Actor* work = g_SpadWork;

    work->unk_09 = 0x28;
    work->unk_2E = 0;
    work->unk_30 = 0x100;
    g_SpadWork->unk_01++;
    SND_PlayCue(0x206);
}
