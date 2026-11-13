#include "magic129_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC10(void) {
    Magic129Steps handlers = D_801EEC04;
    PartyMember*  saved_task;
    PartyMember*  saved_battler;
    u8            i;

    SYS_DISPATCH_BYTE(handlers.steps, g_Task->header.mode);

    for (i = 0; i < BMAGIC_EFFECT_COUNT; i++) {
        if (D_801F05D8[i].header.flags & BMAGIC_EFFECT_IN_USE) {
            saved_task            = g_Task;
            saved_battler         = g_BattleEffectBattler;
            g_Task                = (PartyMember*)&D_801F05D8[i];
            g_BattleEffectBattler = D_801F05D8[i].target.party;
            func_801EFF40();
            g_BattleEffectBattler = saved_battler;
            g_Task                = saved_task;
        }
    }
}

MATCH void func_801EED18(void) {
    u16          i;
    u8           slot;
    u32          member;
    PartyMember* work;

    for (i = 0; i < BMAGIC_EFFECT_COUNT; i++) {
        BMAGIC_EFFECT_SLOTS[i].header.flags = 0;
        BMAGIC_EFFECT_SLOTS[i].header.mode  = 0;
        BMAGIC_EFFECT_SLOTS[i].header.step  = 0;
    }
    Battle_CenterCamera();
    g_Task->param.unk_0B = 0;
    g_Task->unk_09       = 56;
    g_Task->header.mode += 1;
    if (g_Battle.target_selector & BATTLE_TARGET_ENEMY_SIDE) {
        g_Task->header.mode = 2;
        return;
    }
    for (i = 0; i < BATTLE_PARTY_CHARACTERS_COUNT; i++) {
        member = i;
        if (g_Game.members[member].header.flags & PARTY_MEMBER_FLAG_OCCUPIED) {
            slot                               = Battle_AllocEffect(1, 106);
            work                               = g_Task;
            g_BattleEffects[slot].unk_0B       = member << 4;
            g_BattleEffects[slot].header.mode  = 0;
            g_BattleEffects[slot].unk_04       = i;
            g_BattleEffects[slot].arg.unk_09   = 60;
            g_BattleEffects[slot].target.party = work;
            g_Task->param.unk_0B += 1;
        }
    }
}

#include "overlays/bmagic/Effect_RequestTargetOnTimerZero.h"

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

/* func_801EEF80 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EEFC4(void) {
    SYS_DISPATCH_BYTE(D_801F05B8, g_Task->header.step);
    g_Task->param.unk_0B += 1;
    if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
        func_801EF54C();
    }
}

INCLUDE_ASM(func_801EF058);

#include "overlays/bmagic/Effect_CountUpTimerByTwoAndStep.h"

MATCH void func_801EF3DC(void) {
    PartyMember* battler;
    u8           slot;
    u8           timer;

    if (g_Task->unk_09 >= 17 && (g_FrameCount & 0x3) == 0) {
        slot                                   = BMagic_AllocEffect();
        battler                                = g_BattleEffectBattler;
        BMAGIC_EFFECT_SLOTS[slot].header.mode  = 0;
        BMAGIC_EFFECT_SLOTS[slot].target.party = battler;
        BMAGIC_EFFECT_SLOTS[slot].unk_0B       = RANDOM_MASK(0x1F);
        BMAGIC_EFFECT_SLOTS[slot].arg.unk_09   = 1;
        g_BattleEffectBattler->param.unk_0B += 1;
    }
    timer          = g_Task->unk_09 - 1;
    g_Task->unk_09 = timer;
    if (timer == 0) {
        g_Task->header.step += 1;
    }
}

MATCH void func_801EF4F0(void) {
    PartyMember* work;
    s8           timer;

    work         = g_Task;
    timer        = work->unk_5D - 1;
    work->unk_5D = timer;
    if (timer == 0) {
        work               = g_BattleEffectBattler;
        work->param.unk_0B = work->param.unk_0B - 1;
        func_801E5988();
    }
}

INCLUDE_ASM(func_801EF54C);

MATCH void func_801EFF40(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 5), 1, g_Task);
}

MATCH void func_801EFF84(void) {
    s32 tpage;

    SYS_DISPATCH_BYTE((g_BMagicEffectModes + 6), g_Task->header.step);
    if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
        if (GetGraphType() == 1 || GetGraphType() == 2) {
            tpage = 0xA5;
        } else {
            tpage = 0x35;
        }
        SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
        Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(DR_MODE));
        func_800AF764();
        func_801F030C();
        if (GetGraphType() == 1 || GetGraphType() == 2) {
            tpage = 0x25;
        } else {
            tpage = 0x15;
        }
        SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
        Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(DR_MODE));
    }
}

MATCH void func_801F00D4(void) {
    s32 value;
    s32 value2;
    u8  value3;

    value3         = g_Task->unk_09 - 1;
    g_Task->unk_09 = value3;
    if (!(value3 & BYTE_MASK)) {
        g_Task->unk_14      = 0x40000;
        g_Task->unk_20      = 0x20000;
        value2              = RANDOM_MASK(0xF) + 0x1C;
        value               = (g_Task->param.unk_0B & 0x1F) << 7;
        g_Task->pos.x.fixed = g_BattleEffectBattler->pos.x.fixed + (rsin(value) * value2);
        g_Task->pos.y.fixed = g_BattleEffectBattler->pos.y.fixed + (rcos(value) * value2);
        g_Task->pos.z.fixed = g_BattleEffectBattler->pos.z.fixed;
        g_Task->unk_5D      = RANDOM_MASK(7) + 5;
        g_Task->unk_5E      = RANDOM_MASK(7) + 5;
        g_Task->unk_5F      = RANDOM_MASK(7) + 5;
        g_Task->unk_09      = 0x10;
        g_Task->timer       = 16;
        g_Task->header.step += 1;
    }
}

MATCH void func_801F023C(void) {
    PartyMember* work  = g_Task;
    u8           timer = work->unk_09 - 1;
    s32          value = work->unk_14 + work->unk_20;
    work->unk_09       = timer;
    work->unk_14       = value;
    work->pos.z.fixed += value;
    if (timer == 0) {
        g_Task->header.step += 1;
    }
}

MATCH void func_801F029C(void) {
    PartyMember* work  = g_Task;
    u8           timer = work->timer - 1;
    s32          value = work->unk_14 + work->unk_20;
    work->timer        = timer;
    work->unk_14       = value;
    work->pos.z.fixed += value;
    if (timer == 0) {
        g_BattleEffectBattler->param.unk_0B -= 1;
        Actor_Clear();
    }
}

MATCH void func_801F030C(void) {
    POLY_G3* prim;
    SVECTOR* edge;
    s32      radius;
    s32      r;
    s32      g;
    s32      b;
    u8       i;

    D_1F800014[0].vx = g_Task->unk_2E.half + ((rsin(0) * 32) >> 12);
    D_1F800014[0].vy = g_Task->unk_30.half + ((rcos(0) * 32) >> 12);
    r                = (s8)g_Task->unk_5D * g_Task->timer;
    g                = (s8)g_Task->unk_5E * g_Task->timer;
    b                = (s8)g_Task->unk_5F * g_Task->timer;
    i                = 1;
    edge             = &D_1F800014[0];
    radius           = 32;
    do {
        prim = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(prim);
        SetSemiTrans(prim, 1);
        prim->x0 = g_Task->unk_2E.half;
        prim->y0 = g_Task->unk_30.half;
        prim->x1 = edge->vx;
        prim->y1 = edge->vy;
        prim->x2 = edge->vx = g_Task->unk_2E.half + ((rsin(i << 9) * radius) >> 12);
        prim->y2 = edge->vy = g_Task->unk_30.half + ((rcos(i << 9) * radius) >> 12);
        setRGB0(prim, r, g, b);
        setRGB1(prim, 1, 1, 1);
        setRGB2(prim, 1, 1, 1);
        Area_AddCellPrim(g_Task->pos.x.fixed, g_Task->pos.y.fixed, 2, sizeof(POLY_G3));
        i++;
    } while (i < 9);
}

/* func_801F0500 */
#include "overlays/bmagic/BMagic_AllocEffect.h"

/* func_801F0564 */
#include "overlays/bmagic/Actor_Clear.h"
