#include "area197_13.h"

MATCH void func_801F36F0(void) {
    g_SpadWork->unk_09 += 1;
    if (g_SpadWork->unk_09 >= 0x10) {
        Actor_Clear();
    }
    func_801F3768(0x80 - (g_SpadWork->unk_09 << 3), g_SpadWork->unk_09 << 3);
}
