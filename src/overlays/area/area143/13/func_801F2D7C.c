#include "area143_13.h"

MATCH u8* func_801F2D7C(void) {
    u8* p;
    u16 i;

    p = MEM_PTR(u8, 0x800E4800);
    for (i = 0; i < 256; i++) {
        if (p[0] == 0) {
            return p;
        }
        p += 0x18;
    }
    return NULL;
}
