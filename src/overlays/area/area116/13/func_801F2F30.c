#include "area116_13.h"

MATCH void func_801F2F30(void) {
    u8* work;
    s32 pos[3];

    work   = SP_REF(u8*, 0x44);
    pos[0] = *(s32*)(work + 0x34);
    pos[1] = *(s32*)(work + 0x38);
    pos[2] = *(s32*)(work + 0x3C);
    func_801F2F78(pos);
}
