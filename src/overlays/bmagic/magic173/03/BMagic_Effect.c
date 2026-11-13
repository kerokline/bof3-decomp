#include "magic173_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback handlers[2] = {func_801EEC5C, func_801EED90};

    SYS_DISPATCH_TASK(handlers, 1, g_Task);
}

MATCH void func_801EEC5C(void) {
    u32          i;
    u8           slot;
    PartyMember* task;
    PartyMember* work;
    u16*         src;
    u16*         dst;

    g_Task->facing = g_BattleEffectBattler->facing;
    task           = g_Task;
    WorldPos_Copy(&task->pos, &g_BattleEffectBattler->pos);
    task->param.unk_0B = 0;
    g_Task->header.mode += 1;
    for (i = 0; i < 2; i++) {
        slot                               = Battle_AllocEffect(1, 24);
        work                               = g_Task;
        g_BattleEffects[slot].header.mode  = 0;
        g_BattleEffects[slot].unk_04       = i;
        g_BattleEffects[slot].target.party = work;
        g_Task->param.unk_0B += 1;
    }
    i   = 0;
    dst = MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW);
    src = MEM_PTR(u16, AREA_PALETTE_ARENA + 26 * AREA_PALETTE_ROW);
    for (; i < 256; i++) {
        *dst++ = *src++;
    }
    g_GfxPalettePending = 1;
    SND_QueueSelectionFx(EMI_CUE_ID(SND_BANK_COMMON, 0x00));
}

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

/* func_801EEDF0 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EEE34(void) {
    SYS_DISPATCH_BYTE(D_801F0990, g_Task->header.step);
    if (g_Task->unk_04 != 0) {
        if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
            func_801EF4EC();
        }
    } else {
        if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
            func_801EFA34();
        }
    }
}

MATCH void func_801EEEEC(void) {
    PartyMember* target;
    u8           battler;
    u8           kind;
    PartyMember* work;

    target         = g_Battle.selected_actor;
    g_Task->facing = g_BattleEffectBattler->facing;
    battler        = g_Battle.active_battler;
    if (battler < BATTLE_PARTY_CHARACTERS_COUNT) {
        g_Task->unk_0C = 0x4000;
        g_Task->unk_10 = 0;
        g_Task->unk_14 = 0xC00000;
    } else {
        kind = g_BattleEnemyBattlers[battler - BATTLE_PARTY_CHARACTERS_COUNT].enemy_id.byte.kind;
        switch (kind) {
            case 0x61:
                g_Task->unk_0C = 0x38000;
                g_Task->unk_10 = 0;
                g_Task->unk_14 = 0;
                break;
            case 0x6C:
                work = g_Task;
                if (work->facing & 2) {
                    work->unk_0C = 0x20000;
                } else {
                    work->unk_0C = 0x30000;
                }
                work->unk_10 = 0;
                work->unk_14 = 0x800000;
                break;
            default:
                g_Task->unk_0C = 0x10000;
                g_Task->unk_10 = 0;
                g_Task->unk_14 = 0x800000;
                break;
        }
    }
    func_801DD350(g_Task);
    g_Task->pos.x.fixed = g_BattleEffectBattler->pos.x.fixed + g_Task->unk_0C;
    g_Task->pos.y.fixed = g_BattleEffectBattler->pos.y.fixed + g_Task->unk_10;
    g_Task->pos.z.fixed = g_BattleEffectBattler->pos.z.fixed + g_Task->unk_14;
    g_Task->unk_0C      = ratan2(target->pos.x.fixed - g_Task->pos.x.fixed, target->pos.y.fixed - g_Task->pos.y.fixed);
    g_Task->unk_10      = 0;
    Battle_ProjectRange();
    BMagic_Trail[g_Task->unk_04][0].x = g_Task->unk_2E.half;
    BMagic_Trail[g_Task->unk_04][0].y = g_Task->unk_30.half;
    BMagic_Trail[g_Task->unk_04][1].x = g_Task->unk_2E.half;
    BMagic_Trail[g_Task->unk_04][1].y = g_Task->unk_30.half;
    g_Task->param.unk_0B              = 0;
    g_Task->unk_09                    = 16;
    g_Task->timer                     = 1;
    g_Task->header.step++;
}

INCLUDE_ASM(func_801EF148);

MATCH void func_801EF3D8(void) {
    u8 timer;

    if (g_Task->timer < 8U) {
        g_Task->param.unk_0B += 1;
        g_Task->timer += 1;
        Battle_ProjectRange();
        Effect_RecordTrail();
    }
    timer = g_Task->timer;
    if ((timer & BYTE_MASK) == 8) {
        g_Task->unk_09 = timer;
        g_Task->header.step += 1;
    }
}

/* func_801EF484 */
#include "overlays/bmagic/Effect_FinishTrail.h"

INCLUDE_ASM(func_801EF4EC);

INCLUDE_ASM(func_801EFA34);

/* func_801F02B0 */
#include "overlays/bmagic/Effect_RecordTrail.h"

/* func_801F03A0 */
#include "overlays/bmagic/Effect_ClearTrail.h"

MATCH void func_801F0488(void) {
    g_ScriptTable = BMAGIC_SCRIPT_TABLE;
    SYS_DISPATCH_BYTE(D_801F09A0, g_Task->header.step);
    if (g_Task->header.flags != 0) {
        Battle_ProjectRange();
        func_801F075C();
        if (g_Task->header.step < 3) {
            func_8014D290();
        }
    }
    g_ScriptTable = AREA_SCRIPT_TABLE;
}

MATCH void func_801F0540(void) {
    g_Task->unk_25      = 0x1D;
    g_Task->unk_26      = 0;
    g_Task->unk_27      = 0xA0;
    g_Task->unk_28      = 0;
    g_Task->unk_24      = 4;
    g_Task->unk_5D      = 0;
    g_Task->unk_5E      = 0;
    g_Task->unk_5F      = 0;
    g_Task->unk_5C      = 0;
    g_Task->unk_2A      = 0;
    g_Task->unk_29      = 3;
    g_Task->unk_2C.half = 0;
    g_Task->unk_2B      = 1;
    Actor_SelectScript(0U);
    g_Task->unk_09 = 0;
    g_Task->header.step += 1;
}

MATCH void func_801F0648(void) {
    u8 timer;

    Actor_StepAnimOnce();
    timer          = g_Task->unk_09 + 4;
    g_Task->unk_09 = timer;
    if (timer == 16) {
        g_Task->header.step = g_Task->header.step + 1;
    }
}

MATCH void func_801F06B0(void) {
    Actor_StepAnimOnce();
    if (Actor_StepAnimOnce() != 0u) {
        g_Task->header.step = g_Task->header.step + 1;
    }
}

#include "overlays/bmagic/Effect_TickOnTimerZero.h"
MATCH void func_801F075C(void) {
    POLY_G3* prim;
    s32      i;
    s32      tpage;

    if (GetGraphType() == 1) {
        tpage = 0xA5;
    } else if (GetGraphType() == 2) {
        tpage = 0xA5;
    } else {
        tpage = 0x35;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));
    D_1F800000.view.effect.params[0] = (rand() & 3) + 28;
    D_1F800000.view.effect.params[3] = g_Task->unk_09 * 6;
    for (i = 0; i < 8; i++) {
        prim = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(prim);
        SetSemiTrans(prim, 1);
        prim->x0 = g_Task->unk_2E.half;
        prim->y0 = g_Task->unk_30.half;
        prim->x1 = g_Task->unk_2E.half + FIXED_MUL(rsin(i << 9), D_1F800000.view.effect.params[0]);
        prim->y1 = g_Task->unk_30.half + FIXED_MUL(rcos(i << 9), D_1F800000.view.effect.params[0]);
        prim->x2 = g_Task->unk_2E.half + FIXED_MUL(rsin((i + 1) << 9), D_1F800000.view.effect.params[0]);
        prim->y2 = g_Task->unk_30.half + FIXED_MUL(rcos((i + 1) << 9), D_1F800000.view.effect.params[0]);
        prim->r0 = D_1F800000.view.effect.params[3];
        prim->g0 = D_1F800000.view.effect.params[3];
        prim->b0 = D_1F800000.view.effect.params[3];
        setRGB1(prim, 1, 1, 1);
        setRGB2(prim, 1, 1, 1);
        GFX_AddPrim(3, sizeof(POLY_G3));
    }
}
