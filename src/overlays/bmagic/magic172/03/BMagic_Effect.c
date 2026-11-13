#include "magic172_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback handlers[2] = {func_801EEC5C, func_801EEDD8};

    SYS_DISPATCH_TASK(handlers, 1, g_Task);
}

MATCH void func_801EEC5C(void) {
    PartyMember* work;
    PartyMember* target;
    u8           slot;
    u32          first_slot;
    u32          i;

    g_Task->facing       = g_BattleEffectBattler->facing;
    g_Task->pos.x        = g_BattleEffectBattler->pos.x;
    g_Task->pos.y        = g_BattleEffectBattler->pos.y;
    g_Task->pos.z        = g_BattleEffectBattler->pos.z;
    g_Task->param.unk_0B = 0;
    g_Task->header.mode += 1;
    first_slot                               = Battle_AllocEffect(1, 0x51) & BYTE_MASK;
    work                                     = g_Task;
    g_BattleEffects[first_slot].header.mode  = 0;
    g_BattleEffects[first_slot].target.party = work;
    g_Task->param.unk_0B += 1;
    i = 0;
    do {
        slot                               = Battle_AllocEffect(1, 0x51);
        target                             = g_Task;
        g_BattleEffects[slot].header.mode  = 1;
        g_BattleEffects[slot].unk_04       = first_slot;
        g_BattleEffects[slot].arg.unk_09   = i + 1;
        g_BattleEffects[slot].unk_0B       = i;
        g_BattleEffects[slot].target.party = target;
        g_Task->param.unk_0B += 1;
        i++;
    } while (i < 8);
    SND_QueueSelectionFx(EMI_CUE_ID(SND_BANK_COMMON, 0));
}

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

/* func_801EEE38 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

INCLUDE_ASM(func_801EEE7C);

INCLUDE_ASM(func_801EF158);

MATCH void func_801EF210(void) {
    VECTOR       pos;
    PartyMember* actor;
    s32          diff;
    u8           count;

    count = g_Task->unk_09;
    if (count < 16) {
        g_Task->unk_09 = count + 4;
    }
    actor  = g_Battle.selected_actor;
    pos.vx = (actor->pos.x.fixed >> 9) - 0x4000;
    pos.vy = (actor->pos.y.fixed >> 9) - 0x4000;
    pos.vz = (actor->pos.z.fixed + 0x1000000) >> 17;
    func_800AF3A0(pos, 0x40);
    g_Task->unk_10 = g_Task->unk_0C;
    g_Task->unk_0C = ratan2(actor->pos.x.fixed - g_Task->pos.x.fixed, actor->pos.y.fixed - g_Task->pos.y.fixed);
    if (func_800AF66C((BattleRange*)actor, 0x8000) == 0) {
        diff           = (g_Task->unk_10 & 0xFFF) - (g_Task->unk_0C & 0xFFF);
        g_Task->unk_10 = diff;
        if (diff < 0) {
            g_Task->unk_10 = ~diff + 1;
        }
        if ((u32)(g_Task->unk_10 - 0x601) >= 0x3FF) {
            return;
        }
    }
    Battle_ApplyDamageFlags(g_Battle.target_selector, 0x10);
    SND_QueueSelectionFx(0x101);
    g_Task->unk_09 = 16;
    g_Task->header.step += 1;
}

MATCH void func_801EF3A4(void) {
    u8 counter;
    u8 timer;

    g_Task->param.unk_0B += 2;
    timer = g_Task->timer;
    if (timer < 16U) {
        g_Task->timer = timer + 2;
    }
    counter        = g_Task->unk_09 - 1;
    g_Task->unk_09 = counter;
    if (!(counter & BYTE_MASK)) {
        g_Task->header.step += 1;
    }
}

MATCH void func_801EF430(void) {
    u8 timer_next;

    g_Task->param.unk_0B += 4;
    timer_next    = g_Task->timer - 2;
    g_Task->timer = timer_next;
    if (!(timer_next & BYTE_MASK)) {
        SND_QueueSelectionFx(0x102);
        g_Task->unk_09 = 0x10;
        g_Task->header.step += 1;
    }
}

#include "overlays/bmagic/Effect_TickOnTimerZero.h"

MATCH void func_801EF518(void) {
    D_801F0B90[g_Task->header.step]();
    if (g_Task->header.flags & g_Task->header.step) {
        Battle_ProjectRange();
        func_801F0908();
    }
}

INCLUDE_ASM(func_801EF590);

/* Aims the effect at the selected actor, projects its screen point as the effect's range, and advances once the
 * effect record's step is two. */
MATCH void func_801EF650(void) {
    PartyMember* actor;
    VECTOR       pos;

    if (g_Task->unk_09 < 0x10) {
        g_Task->unk_09 += 4;
    }
    actor  = g_Battle.selected_actor;
    pos.vx = (actor->pos.x.fixed >> 9) - 0x4000;
    pos.vy = (actor->pos.y.fixed >> 9) - 0x4000;
    pos.vz = (actor->pos.z.fixed + TO_COORD(256)) >> 17;
    func_800AF3A0(pos, 0x40);
    g_Task->unk_10 = g_Task->unk_0C;
    g_Task->unk_0C = ratan2(actor->pos.x.fixed - g_Task->pos.x.fixed, actor->pos.y.fixed - g_Task->pos.y.fixed);
    if (g_BattleEffects[g_Task->unk_04].header.step == 2) {
        g_Task->header.step += 1;
    }
}

#include "overlays/bmagic/Effect_TickOnTimerNegative.h"

MATCH void func_801EF7CC(void) {
    POLY_G3* prim;
    u16      x;
    u16      y;
    s32      i;
    s32      tpage;

    tpage = GetGraphType() == 1 || GetGraphType() == 2 ? 0xA5 : 0x35;
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));
    D_1F800000.view.effect.params[2] = 0;
    D_1F800000.view.effect.params[0] = 16;
    x                                = g_Task->unk_2E.half;
    y                                = g_Task->unk_30.half;
    D_1F800000.view.effect.params[3] = g_Task->unk_09 * 12;
    D_1F800000.view.effect.params[4] = g_Task->unk_09 * 2;
    D_1F800000.view.effect.params[5] = g_Task->unk_09 * 2;
    D_1F800000.view.effect.params[6] = g_Task->unk_09 * 14;
    for (i = 0; i < 16; i++) {
        prim = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(prim);
        SetSemiTrans(prim, 1);
        prim->x0                         = x;
        prim->y0                         = y;
        prim->x1                         = x + FIXED_MUL(rsin(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        prim->y1                         = y + FIXED_MUL(rcos(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        D_1F800000.view.effect.params[2] = (i + 1) << 8;
        prim->x2                         = x + FIXED_MUL(rsin(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        prim->y2                         = y + FIXED_MUL(rcos(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        setRGB0(prim, D_1F800000.view.effect.params[3], D_1F800000.view.effect.params[3], D_1F800000.view.effect.params[3]);
        setRGB1(prim, D_1F800000.view.effect.params[4], D_1F800000.view.effect.params[5], D_1F800000.view.effect.params[6]);
        setRGB2(prim, D_1F800000.view.effect.params[4], D_1F800000.view.effect.params[5], D_1F800000.view.effect.params[6]);
        GFX_AddPrim(3, sizeof(POLY_G3));
    }
}

INCLUDE_ASM(func_801EFA2C);

INCLUDE_ASM(func_801EFD04);

INCLUDE_ASM(func_801EFFE8);

INCLUDE_ASM(func_801F02C8);

INCLUDE_ASM(func_801F05E8);

INCLUDE_ASM(func_801F0908);
