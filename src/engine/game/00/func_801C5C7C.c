#include "game_00.h"

MATCH void func_801C5C7C(void) {
    u8* flags;

    if (g_GameStateIndex != 2) {
        flags      = &D_80143FBC;
        D_80143F4A = 0;
        *flags &= 0xDF;
    }
}
