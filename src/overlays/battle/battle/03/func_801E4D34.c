#include "battle_03.h"

MATCH void func_801E4D34(void) {
    if (func_801E3160() != 0u) {
        g_SpadWork->step_01 = (u8)(g_SpadWork->step_01 + 1u);
        g_SpadWork->unk_02  = 0u;
    }
}
