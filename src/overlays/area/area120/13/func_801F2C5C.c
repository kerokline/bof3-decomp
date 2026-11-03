#include "area120_13.h"

MATCH void func_801F2C5C(void) {
    Actor* actor;

    func_801F35B8();
    actor         = g_SpadWork;
    actor->unk_06 = 0;
    actor->unk_32 = 0x78;
    g_SpadWork->unk_01++;
    SND_PlayCue(0x201);
}
