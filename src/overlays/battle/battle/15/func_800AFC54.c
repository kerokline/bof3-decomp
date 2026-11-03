#include "battle_15.h"

MATCH void func_800AFC54(void) {
    u32        i;
    u16*       dst;
    const u16* src;

    i   = 0u;
    dst = MEM_PTR(u16, 0x80037C00u);
    src = MEM_PTR(const u16, 0x80033C00u);
    do {
        *dst++ = *src++;
        i++;
    } while (i < 256u);
    MEM(u8, 0x80145988u) = 1u;
}
