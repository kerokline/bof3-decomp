#include "engine/slus/slus.h"

typedef struct CopyQuad {
    u32 w[4];
} CopyQuad;

/* copies one 0xA4-byte map entry to the stack, patches the byte
 * selected by `sel`, runs the shared handler, then audits four entry halfwords
 * against the handler's result, writing a direction flag and the value.
 */
MATCH void func_80164D2C(u8 idx, u8 sel, u8 val, u8* flags, u16* dst) {
    u8        buf[0xA4];
    u16*      entry_vals[4];
    u16*      buf_vals[4];
    u8*       entry;
    CopyQuad* src;
    CopyQuad* dstbuf = (CopyQuad*)buf;
    s32       i;
    s32       j;

    entry         = (u8*)&g_Characters[(u32)idx];
    entry_vals[0] = (u16*)(entry + 0x20);
    entry_vals[1] = (u16*)(entry + 0x22);
    entry_vals[2] = (u16*)(entry + 0x26);
    entry_vals[3] = (u16*)(entry + 0x24);
    buf_vals[0]   = (u16*)(buf + 0x20);
    buf_vals[1]   = (u16*)(buf + 0x22);
    buf_vals[2]   = (u16*)(buf + 0x26);
    buf_vals[3]   = (u16*)(buf + 0x24);
    src           = (CopyQuad*)entry;
    do {
        *dstbuf = *src;
        src++;
        dstbuf++;
    } while ((u8*)src != entry + 0xA0);
    *(u32*)dstbuf = *(u32*)src;
    /* FAKE: keep the sel mask after the final copy store. */
    MATCH_BARRIER();
    switch (sel) {
        case 0:
            buf[0x0E] = val;
            break;
        case 1:
            buf[0x0F] = val;
            break;
        case 2:
            buf[0x10] = val;
            break;
        case 3:
            buf[0x11] = val;
            break;
        case 4:
            buf[0x12] = val;
            break;
        case 5:
            buf[0x13] = val;
            break;
    }
    Char_RebuildStats((Character*)buf);
    for (i = 0; (u32)(u8)i < 4; i++) {
        j        = i & BYTE_MASK;
        flags[j] = 0;
        dst[j]   = *buf_vals[j];
        if (*entry_vals[j] < *buf_vals[j])
            flags[j] = 3;
        if (*entry_vals[j] > *buf_vals[j])
            flags[j] = 2;
    }
}
