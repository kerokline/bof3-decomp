#include "area105_13.h"

MATCH void func_801F2C94(void) {
    if (g_AreaSceneMode == 1) {
        u8* work = SP_REF(u8*, 0x44);

        work[2] += 1;
        func_801F2D9C(0);
    }
}
