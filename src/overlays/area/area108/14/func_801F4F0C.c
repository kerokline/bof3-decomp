#include "area108_14.h"

MATCH void func_801F4F0C(void) {
    if (g_GameStateIndex == GAME_REQUEST_AREA_CHANGE) {
        func_801F55F0(0);
    } else {
        *(s16*)((u8*)g_ScriptState + 0xA) -= 2;
    }
}
