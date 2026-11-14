#include "magic107_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    ACTOR_RUN_MODE_HANDLER(func_801EEC5C, func_801EED40);
}

/* The g_Task base for the span read must be fetched before the D_801EC364 store and the
 * z member read kept in place; both inline reads or an early span local shift the reload. */
MATCH void func_801EEC5C(void) {
    PartyMember* work;
    s32          scroll_x;
    u32          offset;

    Battle_CenterCamera();
    offset                                  = (Battle_AllocEffect(1, 25) & BYTE_MASK) * BATTLE_EFFECT_STRIDE;
    FIELD(PartyMember*, D_801EC3A4, offset) = g_Task;
    FIELD(u8, D_801EC338, offset)           = ((PartyMember*)D_8014637C)->facing;
    scroll_x                                = g_AreaScrollTargetX;
    work                                    = g_Task;
    FIELD(s32, D_801EC364, offset)          = scroll_x;
    FIELD(s32, D_801EC368, offset)          = g_AreaScrollTargetY;
    FIELD(s32, D_801EC36C, offset)          = work->pos.z.fixed + 0x04000000;
    SND_QueueSelectionFx(0x100);
    g_Task->param.unk_0B = 0;
    g_Task->header.mode += 1;
}

#include "overlays/bmagic/Effect_PlayOnIdleTick.h"

MATCH void func_801EEDA0(void) {
    SYS_DISPATCH_BYTE(D_801F048C, g_Task->header.mode);
    if (g_Task->header.flags != 0) {
        func_801EEFD4();
        func_801EF0E4();
        func_801EF544();
        func_801EF290();
        PopMatrix();
        Effect_SetActorMatrixQuarterRoll();
        func_801F01AC();
        func_801EFAE0();
        func_801EFEA8();
        PopMatrix();
    }
}

MATCH void func_801EEE50(void) {
    g_Task->param.unk_0B = 0;
    g_Task->unk_09       = 0;
    g_Task->timer        = 0;
    g_Task->header.mode++;
}

MATCH void func_801EEEA0(void) {
    g_Task->unk_09 += 1;
    g_Task->timer += 1;
    if (g_Task->unk_09 == 0x20) {
        g_Task->header.mode = g_Task->header.mode + 1;
    }
}

#include "overlays/bmagic/Effect_AdvanceOnTick.h"

MATCH void func_801EEF5C(void) {
    PartyMember* active;

    g_Task->unk_09 = g_Task->unk_09 + 1;
    g_Task->timer  = g_Task->timer - 1;
    if (g_Task->timer == 0) {
        active               = BATTLE_ACTIVE_WORK;
        active->param.unk_0B = 255;
        func_801E5988();
    }
}

MATCH void func_801EEFD4(void) {
    SVECTOR pos;
    SVECTOR rot;
    MATRIX  matrix;
    long    flags;
    u8      angle;

    PushMatrix();
    if (g_Task->facing & 0x1) {
        rot.vx = 0;
        angle  = g_Task->unk_09 & 0x3F;
        rot.vy = (u32)rsin(angle << 6) >> 3;
        rot.vz = 0;
    } else {
        angle  = g_Task->unk_09 & 0x3F;
        rot.vx = (u32)rsin(angle << 6) >> 3;
        rot.vy = 0;
        rot.vz = 0;
    }
    BMAGIC_PROJECT_ACTOR_MATRIX(g_Task);
}

MATCH void func_801EF0E4(void) {
    LINE_G3* prim;
    long     depth;
    long     flag;
    s32      tpage;
    s32*     shade;

    if (GetGraphType() == 1 || GetGraphType() == 2) {
        tpage = 0xA5;
    } else {
        tpage = 0x35;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(DR_MODE));
    prim = (LINE_G3*)g_GfxPrimCursor;
    SetLineG3(prim);
    SetSemiTrans(prim, 1);
    D_1F800000.view.effect.vectors[0].vy = 0;
    D_1F800014[0].vx                     = 0;
    D_1F800000.view.effect.vectors[0].vz = 0;
    D_1F800000.view.effect.vectors[1].vy = 0;
    D_1F800014[1].vx                     = 0;
    D_1F800000.view.effect.vectors[1].vz = 0x170;
    D_1F800000.view.effect.vectors[2].vy = 0;
    D_1F800014[2].vx                     = 0;
    D_1F800000.view.effect.vectors[2].vz = 384;
    RotTransPers3(&D_1F800014[0], &D_1F800014[1], &D_1F800014[2], (long*)&prim->x0, (long*)&prim->x1, (long*)&prim->x2, &depth, &flag);
    shade  = &D_1F80000C;
    *shade = g_Task->timer * 6;
    setRGB0(prim, *shade, *shade, *shade);
    setRGB1(prim, *shade, *shade, *shade);
    setRGB2(prim, 1, 1, 1);
    Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(LINE_G3));
}

MATCH void func_801EF290(void) {
    POLY_F3* prim;
    long     depth;
    long     flag;
    s32      i;
    s32      semi;
    s32      tpage;

    semi = g_Task->header.mode & 1;
    if (GetGraphType() == 1) {
        tpage = (semi << 7) | 0x25;
    } else if (GetGraphType() == 2) {
        tpage = (semi << 7) | 0x25;
    } else {
        tpage = (semi << 5) | 0x15;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(DR_MODE));
    D_1F800000.view.scenario.math_00 = 32;
    D_1F800014[2].vx                 = FIXED_MUL(rsin(0), D_1F800000.view.scenario.math_00);
    D_1F800014[2].vy                 = FIXED_MUL(rcos(0), D_1F800000.view.scenario.math_00);
    D_1F800014[2].vz                 = 448;
    for (i = 1; i <= 16; i++) {
        D_1F800014[0].vx = 0;
        D_1F800014[0].vy = 0;
        D_1F800014[0].vz = 384;
        D_1F800014[1].vx = D_1F800014[2].vx;
        D_1F800014[1].vy = D_1F800014[2].vy;
        D_1F800014[1].vz = D_1F800014[2].vz;
        D_1F800014[2].vx = FIXED_MUL(rsin(i << 8), D_1F800000.view.scenario.math_00);
        D_1F800014[2].vy = FIXED_MUL(rcos(i << 8), D_1F800000.view.scenario.math_00);
        D_1F800014[2].vz = 448;
        if (i < 8 || i > 12) {
            prim = (POLY_F3*)g_GfxPrimCursor;
            SetPolyF3(prim);
            SetSemiTrans(prim, semi);
            RotTransPers3(&D_1F800014[0], &D_1F800014[1], &D_1F800014[2], (long*)&prim->x0, (long*)&prim->x1, (long*)&prim->x2, &depth, &flag);
            if (g_Task->header.mode & 1) {
                setRGB0(prim, g_Task->timer * 6, 1, 1);
            } else {
                if (i < 8) {
                    D_1F800000.view.scenario.math_0C = 145 - i * 16;
                } else {
                    D_1F800000.view.scenario.math_0C = (i - 8) * 16 + 17;
                }
                setRGB0(prim, 192, D_1F800000.view.scenario.math_0C, 16);
            }
            Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(POLY_F3));
        }
    }
}

INCLUDE_ASM(func_801EF544);

#include "overlays/bmagic/Effect_SetActorMatrixQuarterRoll.h"

INCLUDE_ASM(func_801EFAE0);

INCLUDE_ASM(func_801EFEA8);

INCLUDE_ASM(func_801F01AC);
