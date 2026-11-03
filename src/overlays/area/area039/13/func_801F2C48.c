#include "area039_13.h"

MATCH void func_801F2C48(void) {
    ((u8*)g_SpadWork)[0xA] = 0x40;
    ((u8*)g_SpadWork)[0x4] = 1;
    *(u16*)((u8*)g_CurrentActor + 0x7E) -= 2;
}
