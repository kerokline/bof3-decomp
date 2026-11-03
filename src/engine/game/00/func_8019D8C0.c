#include "game_00.h"

MATCH void func_8019D8C0(void* obj, s16* out) {
    MATRIX rot;
    VECTOR vtx;
    long   flag;
    s16*   dst;
    s32    index;

    dst = out;
    PushMatrix();
    dst += 1;
    FIELD(s16, obj, 0x10u) = (s16)(rand() & 0xFC0);
    FIELD(s16, obj, 0x12u) = (s16)(rand() & 0xFC0);
    FIELD(s16, obj, 0x14u) = (s16)(rand() & 0xFC0);
    RotMatrix(obj + 0x10, &rot);
    rot.t[0] = 0;
    rot.t[1] = 0;
    rot.t[2] = 0;
    SetTransMatrix(&rot);
    SetRotMatrix(&rot);
    index = 0;
    do {
        RotTrans(obj + (((index & BYTE_MASK) * 8) + 0x18), &vtx, &flag);
        index += 1;
        *dst = (*((u16*)obj)) + vtx.vx;
        dst += 1;
        *dst = FIELD(u16, obj, 0x2u) + vtx.vy;
        dst += 1;
        *dst = FIELD(u16, obj, 0x4u) + vtx.vz;
        dst += 1;
    } while (((u32)(index & BYTE_MASK)) < 4U);
    PopMatrix();
}
