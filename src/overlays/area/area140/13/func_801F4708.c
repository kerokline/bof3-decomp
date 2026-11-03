#include "area140_13.h"

MATCH void func_801F4708(void) {
    u8* work;

    work = (u8*)g_SpadWork;
    work[9]--;
    if (work[9] == 0) {
        g_SpadWork->unk_01 = 2;
    }
    if (g_GameStateIndex == 5) {
        g_SpadWork->unk_01 = 2;
    }
}
