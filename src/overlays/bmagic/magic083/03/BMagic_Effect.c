#include "magic083_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/Effect_RunSlotsWithSetup.h"

INCLUDE_ASM(func_801EED04);

#include "overlays/bmagic/Effect_StartOnZeroTick.h"

MATCH s32 func_801EF0CC(void) {
    if (*((u8*)&g_Battle.action_type) != BATTLE_ACTION_ABILITY && *((u16*)&g_Battle.action_id) == 0x136) {
        g_Battle.action_id = ABILITY_SHIELD;
    }
    return 0;
}

/* func_801EF108 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EF14C(void) {
    SYS_DISPATCH_BYTE(D_801F0EF0, g_Task->header.step);
    if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
        Effect_SetActorMatrix();
        func_801EFB24();
        func_801EF844();
        PopMatrix();
    }
}

MATCH void func_801EF1DC(void) {
    void* battler;
    u8    count;

    count          = g_Task->unk_09 - 1;
    g_Task->unk_09 = count;
    if (count == 0) {
        if (g_Battle.target_selector & BATTLE_TARGET_ENEMY_SIDE) {
            battler = &g_BattleEnemyBattlers[g_Task->unk_03];
        } else {
            battler = &g_Game.members[g_Task->unk_03];
        }
        GFX_FreePaletteFadeTarget(battler);
        g_Task->timer  = GFX_AllocPaletteFade(battler, 0, 0, 0, 1);
        g_Task->unk_09 = 0;
        g_Task->header.step += 1;
    }
}

MATCH void func_801EF2F8(void) {
    PartyMember* owner;
    u8           slot;
    u8           base;
    u8           i;

    if (g_PaletteFades[g_Task->timer].offset.red != 8) {
        g_PaletteFades[g_Task->timer].offset.red++;
        g_PaletteFades[g_Task->timer].offset.green++;
        g_PaletteFades[g_Task->timer].offset.blue++;
    }
    if (++g_Task->unk_09 == 16) {
        base                 = g_Task->param.unk_0B;
        g_Task->param.unk_0B = 0;
        for (i = 0; i < 3; i++) {
            slot = BMagic_AllocEffect();
            if (slot != 0xFF) {
                owner                                  = g_Task;
                BMAGIC_EFFECT_SLOTS[slot].header.mode  = 0;
                BMAGIC_EFFECT_SLOTS[slot].header.step  = 0;
                BMAGIC_EFFECT_SLOTS[slot].unk_03       = base + (i << 4);
                BMAGIC_EFFECT_SLOTS[slot].target.party = owner;
                BMAGIC_EFFECT_SLOTS[slot].unk_04       = g_Task->unk_04;
                BMAGIC_EFFECT_SLOTS[slot].unk_0B       = i * 10;
                BMAGIC_EFFECT_SLOTS[slot].arg.unk_09   = i * 8 + 1;
                BMAGIC_EFFECT_SLOTS[slot].unk_0A       = 1;
                g_Task->param.unk_0B++;
            }
        }
        g_Task->header.step++;
    }
}

#include "overlays/bmagic/Effect_StepOnZeroTick.h"

MATCH void func_801EF55C(void) {
    PartyMember* battler;
    u8           slot;

    if (g_Battle.target_selector & BATTLE_TARGET_ENEMY_SIDE) {
        slot    = g_Task->unk_03 + 3;
        battler = (PartyMember*)&g_BattleEnemyBattlers[g_Task->unk_03];
    } else {
        slot    = g_Task->unk_03;
        battler = &g_Game.members[slot];
    }
    if (g_PaletteFades[g_Task->timer].offset.red != 0) {
        g_PaletteFades[g_Task->timer].offset.red--;
        g_PaletteFades[g_Task->timer].offset.green--;
        g_PaletteFades[g_Task->timer].offset.blue--;
    }
    if (--g_Task->unk_09 == 0) {
        GFX_FreePaletteFadeTarget(battler);
        func_800AF814(slot);
        func_800AEEC8(g_Task->unk_04, g_Task->unk_03);
        g_Task->param.unk_0B++;
        g_Task->header.step++;
    }
}

#include "overlays/bmagic/Effect_TickOnZeroTick.h"

#include "overlays/bmagic/Effect_SetActorMatrix.h"

INCLUDE_ASM(func_801EF844);

INCLUDE_ASM(func_801EFB24);

MATCH void func_801EFE54(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 6), 1, g_Task);
}

MATCH void func_801EFE98(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 7), 2, g_Task);
}

INCLUDE_ASM(func_801EFEDC);

MATCH void func_801F0010(void) {
    s32          timer;
    s32          vel;
    PartyMember* task;
    PartyMember* reset;

    Battle_ProjectRange();
    func_801F0BA8((RANDOM_MASK(3)) | 0x18);
    Effect_SetActorMatrix();
    func_801F050C();
    PopMatrix();
    if (g_FrameCount & 0x1) {
        g_Task->unk_09 += 1;
    }
    task         = g_Task;
    timer        = task->timer - 1;
    vel          = task->unk_14 + task->unk_20;
    task->timer  = timer;
    task->unk_14 = vel;
    task->pos.z.part.integer += vel;
    if ((timer & BYTE_MASK) == 0) {
        reset         = g_Task;
        reset->unk_14 = -0x10;
        reset->timer  = 8;
        reset->unk_20 = 4;
        g_Task->header.step += 1;
    }
}

MATCH void func_801F0104(void) {
    s32          timer;
    s32          vel;
    PartyMember* task;

    Battle_ProjectRange();
    func_801F0BA8((RANDOM_MASK(3)) | 0x18);
    Effect_SetActorMatrix();
    func_801F050C();
    PopMatrix();
    if (g_FrameCount & 0x1) {
        g_Task->unk_09 += 1;
    }
    task         = g_Task;
    timer        = task->timer - 1;
    vel          = task->unk_14 + task->unk_20;
    task->timer  = timer;
    task->unk_14 = vel;
    task->pos.z.part.integer += vel;
    if ((timer & BYTE_MASK) == 0) {
        g_Task->timer = 28 - g_Task->param.unk_0B;
        g_Task->header.step += 1;
    }
}

MATCH void func_801F01F8(void) {
    s32 value;
    s32 value2;
    s32 value3;
    u8  value4;
    u8  value5;

    Battle_ProjectRange();
    if ((g_Task->unk_0C == 4) && (g_Task->timer < 5U)) {
        value2 = (RANDOM_MASK(3)) | 0x40;
    } else {
        value2 = (RANDOM_MASK(3)) | 0x18;
    }
    func_801F0BA8(value2);
    Effect_SetActorMatrix();
    func_801F050C();
    PopMatrix();
    if (g_Task->unk_0C < 4) {
        value          = g_Task->unk_10 + 1;
        g_Task->unk_10 = value;
        if (!(value & 0x7)) {
            g_Task->unk_0C += 1;
        }
    }
    g_Task->unk_09 += g_Task->unk_0C;
    if (g_Task->unk_0C == 4) {
        value4        = g_Task->timer - 1;
        g_Task->timer = value4;
        if (!(value4 & BYTE_MASK)) {
            value5 = g_Task->unk_03;
            if (!(value5 & 0xF0)) {
                value3 = 0x102;
                if (value5 & 0x1) {
                    value3 = 0x101;
                }
                SND_QueueSelectionFx(value3);
            }
            g_Task->unk_10 = 8;
            g_Task->unk_14 = 8;
            g_Task->unk_20 = 8;
            g_Task->header.step += 1;
        }
    }
}

INCLUDE_ASM(func_801F038C);

INCLUDE_ASM(func_801F050C);

MATCH void func_801F0BA8(s32 radius) {
    POLY_G3* poly;
    s32      tpage;
    s32      i;

    D_1F800000.view.effect.params[0] = radius;
    i                                = 0;
    do {
        tpage = GetGraphType() == 1 || GetGraphType() == 2 ? 0xA5 : 0x35;
        SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
        Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(DR_MODE));
        poly = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(poly);
        SetSemiTrans(poly, 1);
        poly->x0 = g_Task->unk_2E.half;
        poly->y0 = g_Task->unk_30.half;
        poly->x1 = g_Task->unk_2E.half + ((rsin(i << 9) * D_1F800000.view.effect.params[0]) >> 12);
        poly->y1 = g_Task->unk_30.half + ((rcos(i << 9) * D_1F800000.view.effect.params[0]) >> 12);
        poly->x2 = g_Task->unk_2E.half + ((rsin((i + 1) << 9) * D_1F800000.view.effect.params[0]) >> 12);
        poly->y2 = g_Task->unk_30.half + ((rcos((i + 1) << 9) * D_1F800000.view.effect.params[0]) >> 12);
        poly->r0 = 0x80;
        poly->g0 = 0x80;
        poly->b0 = 0x80;
        poly->r1 = 1;
        poly->g1 = 1;
        poly->b1 = 1;
        poly->r2 = 1;
        poly->g2 = 1;
        poly->b2 = 1;
        Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(POLY_G3));
        i++;
    } while (i < 8);
}

/* func_801F0DC0 */
#include "overlays/bmagic/BMagic_AllocEffect.h"

/* func_801F0E24 */
#include "overlays/bmagic/Actor_Clear.h"
