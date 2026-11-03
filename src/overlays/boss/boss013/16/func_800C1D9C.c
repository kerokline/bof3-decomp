#include "boss013_16.h"

MATCH void func_800C1D9C(void) {
    Area_FindSceneRecord(0xF9);
    g_SpadWork[0x24] &= 0xFE;
    Actor_SelectScript(2);
    g_SpadWork[2]++;
}
