#include "engine/slus/slus.h"

typedef struct {
    s32 w[4];
} Quad;

/* copies one record, patches 6 bytes, recalculates it, then flags 4
 * field comparisons.
 */
MATCH void func_80164EF8(s32 index, u8* patch, u8* flags, u16* values) {
    s32  copy[0x29];
    u16* org[4];
    u16* loc[4];
    s32* src;
    /* FAKE: retail computes the record base in v0. */
    MATCH_REG(s32*, record, "v0");
    s32* dst;
    s32* end;
    u8   i;

    dst    = copy;
    record = (s32*)(&g_Characters[index & BYTE_MASK]);
    src    = record;
    end    = record + 0x28;
    org[0] = (u16*)((u8*)src + 0x20);
    org[1] = (u16*)((u8*)src + 0x22);
    org[2] = (u16*)((u8*)src + 0x26);
    org[3] = (u16*)((u8*)src + 0x24);
    loc[0] = (u16*)((u8*)copy + 0x20);
    loc[1] = (u16*)((u8*)copy + 0x22);
    loc[2] = (u16*)((u8*)copy + 0x26);
    loc[3] = (u16*)((u8*)copy + 0x24);
    do {
        *(Quad*)dst = *(Quad*)src;
        src += 4;
        dst += 4;
    } while (src != end);
    *dst              = *src;
    ((u8*)copy)[0x0E] = patch[0];
    ((u8*)copy)[0x0F] = patch[1];
    ((u8*)copy)[0x10] = patch[2];
    ((u8*)copy)[0x11] = patch[3];
    ((u8*)copy)[0x12] = patch[4];
    ((u8*)copy)[0x13] = patch[5];
    Char_RebuildStats((Character*)copy);
    for (i = 0; i < 4; i++) {
        flags[i]  = 0;
        values[i] = *loc[i];
        if (*org[i] < *loc[i]) {
            flags[i] = 3;
        }
        if (*org[i] > *loc[i]) {
            flags[i] = 2;
        }
    }
}
