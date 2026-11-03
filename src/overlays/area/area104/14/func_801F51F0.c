#include "area104_14.h"

MATCH void func_801F51F0(void) {
    if ((g_InputHeld & D_80145AB6) && g_SpadWork->unk_0B < 0x40) {
        g_GameState->counter_11C.u8_value = 4;
    } else {
        g_GameState->counter_11C.u8_value = 3;
    }
}
