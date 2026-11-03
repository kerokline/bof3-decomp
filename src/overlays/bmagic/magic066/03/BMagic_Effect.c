#include "magic066_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_RunStep.h"

INCLUDE_ASM(func_801EEC70);

INCLUDE_ASM(func_801EEDB8);

#include "overlays/bmagic/Effect_PlayOnIdleTick.h"

MATCH void func_801EEEBC(void) {
    SYS_DISPATCH_BYTE(g_BMagicEffectFuncs, ((u8*)g_SpadWork)[1]);
}

INCLUDE_ASM(func_801EEF00);

INCLUDE_ASM(func_801EEF78);

INCLUDE_ASM(func_801EEFF8);

INCLUDE_ASM(func_801EF04C);

INCLUDE_ASM(func_801EF0A4);

INCLUDE_ASM(func_801EF108);

INCLUDE_ASM(func_801EF158);

#include "overlays/bmagic/Effect_SetActorMatrix.h"

MATCH void func_801EF834(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectFuncs + 7), 2, g_SpadWork);
}

INCLUDE_ASM(func_801EF878);

INCLUDE_ASM(func_801EF8C8);

INCLUDE_ASM(func_801EF930);

INCLUDE_ASM(func_801EF984);

INCLUDE_ASM(func_801EFCC8);

MATCH void func_801EFFB0(void) {
    SVECTOR pos;
    SVECTOR rot;
    MATRIX  matrix;
    long    flags;

    PushMatrix();
    rot.vx = 3072;
    rot.vy = 0;
    rot.vz = 0;
    pos.vx = (g_SpadWork->coord_x_34.raw >> 9) - 0x4000;
    pos.vy = (g_SpadWork->coord_y_38.raw >> 9) - 0x4000;
    pos.vz = -g_SpadWork->word_3C.half.span_3E / 2;
    RotTrans(&pos, &matrix.t, &flags);
    RotMatrix(&rot, &matrix);
    MulMatrix2((MATRIX*)g_CameraMatrix, &matrix);
    SetRotMatrix(&matrix);
    SetTransMatrix(&matrix);
}
