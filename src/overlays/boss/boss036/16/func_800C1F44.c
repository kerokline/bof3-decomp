#include "boss036_16.h"

MATCH void func_800C1F44(void) {
    g_SpadWork[0xB] = 0;
    g_SpadWork[9]   = 0;
    Actor_SelectScript(1);
    func_8014D978();
    Area_AddActor();
    g_SpadWork[2]++;
}
