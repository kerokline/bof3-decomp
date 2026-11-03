#include "area068_13.h"

MATCH void func_801F3538(void) {
    if (g_InputPressed == PADRdown) {
        D_801F4E04 += 1;
        FIELD(s8, (SP_REF(void*, 0x44)), 0x1u) = 0x10;
    }
}
