#include "magic094_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback table[2] = {func_801EEC5C, func_801EED60};

    table[SP_REF(u8*, 0x44)[1]]();
}

INCLUDE_ASM(func_801EEC5C);

INCLUDE_ASM(func_801EED60);

INCLUDE_ASM(func_801EEE4C);

MATCH void func_801EEF1C(void) {
    func_800A9610(g_BattleTargetSelector, 32);
    g_SpadWork->unk_09 = 0;
    g_SpadWork->unk_0A = 0;
    g_SpadWork->step_01++;
}

INCLUDE_ASM(func_801EEF7C);

INCLUDE_ASM(func_801EF078);

INCLUDE_ASM(func_801EF0FC);

INCLUDE_ASM(func_801EF14C);

MATCH void func_801EF654(void) {
    SVECTOR pos;
    SVECTOR rot;
    MATRIX  matrix;
    long    flags;

    PushMatrix();
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = g_SpadWork->unk_0A << 4;
    pos.vx = (g_SpadWork->coord_x_34.raw >> 9) - 0x4000;
    pos.vy = (g_SpadWork->coord_y_38.raw >> 9) - 0x4000;
    pos.vz = -g_SpadWork->word_3C.half.span_3E / 2;
    RotTrans(&pos, &matrix.t, &flags);
    RotMatrix(&rot, &matrix);
    MulMatrix2((MATRIX*)g_CameraMatrix, &matrix);
    SetRotMatrix(&matrix);
    SetTransMatrix(&matrix);
}

INCLUDE_ASM(func_801EF710);
