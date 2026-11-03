#include "engine/slus/slus.h"

/* transforms a point by the camera and object matrices: builds the rotation
 * matrix from the D_801481D8 triple, rotates the D_80149BF0 translation
 * through the object angle, applies the transposed input rotation, and writes
 * the 16.16 result to the caller.
 */
MATCH void func_8015B2AC(s16* out, s32* in) {
    MATRIX  matrix;
    VECTOR  vec;
    SVECTOR rot;
    long    flag;

    vec           = D_80149BF0;
    D_801481D8.vx = D_801481E0;
    D_801481D8.vy = D_801481E2;
    D_801481D8.vz = D_801481E4;
    PushMatrix();
    RotMatrix(&D_801481D8, &matrix);
    TransMatrix(&matrix, &vec);
    SetRotMatrix(&matrix);
    SetTransMatrix(&matrix);
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = D_801481E6;
    RotTrans(&rot, &vec, &flag);
    rot.vx = (s16)in[0];
    rot.vy = (s16)in[1];
    rot.vz = (s16)in[2];
    RotMatrix(&rot, &matrix);
    TransposeMatrix(&matrix, &matrix);
    ApplyMatrixLV(&matrix, &vec, &vec);
    out[0] = (s16)vec.vx;
    out[1] = (s16)vec.vy;
    out[2] = (s16)vec.vz;
    PopMatrix();
}
