#include "boss025_13.h"

MATCH void func_800C2074(void) {
    Actor_RequestScript(0xD);
    g_SpadWork[0x2A] = 0;
    func_8014DAEC();
    func_801E54EC();
    g_SpadWork[0] &= ~ACTOR_FLAG_HIDDEN;
    ACTOR_SET_STEP(3);
    g_SpadWork[2] = 0;
    g_SpadWork[3] = 0;
}
