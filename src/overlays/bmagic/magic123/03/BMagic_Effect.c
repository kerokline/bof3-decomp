#include "magic123_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    PartyMember* saved_task;
    PartyMember* saved_battler;
    s32          tpage;
    u8           i;

    BMagic_DispatchTaskPair(func_801EEDAC, Effect_PlayOnZeroTick);
    if (GetGraphType() == 1 || GetGraphType() == 2) {
        tpage = 0xA5;
    } else {
        tpage = 0x35;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));

    for (i = 0; i < BMAGIC_EFFECT_COUNT; i++) {
        if (BMAGIC_EFFECT_SLOTS[i].header.flags & BMAGIC_EFFECT_IN_USE) {
            saved_task            = g_Task;
            saved_battler         = g_BattleEffectBattler;
            g_Task                = (PartyMember*)&BMAGIC_EFFECT_SLOTS[i];
            g_BattleEffectBattler = BMAGIC_EFFECT_SLOTS[i].target.party;
            BMagic_DispatchEffectMode();
            g_BattleEffectBattler = saved_battler;
            g_Task                = saved_task;
        }
    }

    if (GetGraphType() == 1 || GetGraphType() == 2) {
        tpage = 0x25;
    } else {
        tpage = 0x15;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));
}

INCLUDE_ASM(func_801EEDAC);

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

/* func_801EF0C4 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EF108(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 2), 2, g_Task);
}

MATCH void func_801EF14C(void) {
    u8 timer;

    timer          = g_Task->unk_09 - 1;
    g_Task->unk_09 = timer;
    if (!(timer & BYTE_MASK)) {
        g_Task->unk_2E.half = g_BattleEffectBattler->unk_2E.half;
        g_Task->unk_30.half = g_BattleEffectBattler->unk_30.half;
        if RANDOM_MASK (1) {
            g_Task->unk_14 = g_BattleEffectBattler->unk_14 + RANDOM_MASK(BYTE_MASK);
        } else {
            g_Task->unk_14 = g_BattleEffectBattler->unk_14 - RANDOM_MASK(BYTE_MASK);
        }
        g_Task->unk_03       = RANDOM_MASK(7);
        g_Task->unk_0C       = RANDOM_MASK(7) + 8;
        g_Task->param.unk_0B = rand();
        g_Task->unk_09       = RANDOM_MASK(0xF) + 8;
        g_Task->timer        = 2;
        g_Task->header.step += 1;
    }
}

INCLUDE_ASM(func_801EF28C);

MATCH void func_801EF4AC(void) {
    u8 timer;

    g_Task->param.unk_0B += 1;
    g_Task->unk_09 += 1;
    timer         = g_Task->timer - 1;
    g_Task->timer = timer;
    if (!(timer & BYTE_MASK)) {
        BATTLE_ACTIVE_WORK->param.unk_0B -= 1;
        Actor_Clear();
        return;
    }
    func_801EF9E0();
}

/* func_801EF550 */
MATCH void Effect_ClearEffect(void) {
    BATTLE_ACTIVE_WORK->param.unk_0B--;
    Actor_Clear();
}

MATCH void func_801EF584(void) {
    POLY_G3* prim;
    s32      i;
    u8       phase;

    D_1F800000.view.effect.params[0] = g_Task->timer;
    for (i = 0; i < 6; i++) {
        prim = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(prim);
        SetSemiTrans(prim, 1);
        prim->x0                         = D_1F800000.view.effect.params[3];
        prim->y0                         = D_1F800000.view.effect.params[4];
        phase                            = (D_801EFD6C[i] + g_Task->unk_09) & 0x3F;
        D_1F800000.view.effect.params[2] = phase << 6;
        prim->x1                         = D_1F800000.view.effect.params[3] + FIXED_MUL(rsin(phase << 6), D_1F800000.view.effect.params[0]);
        prim->y1                         = D_1F800000.view.effect.params[4] + FIXED_MUL(rcos(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        phase                            = (D_801EFD6C[i + 1] + g_Task->unk_09) & 0x3F;
        D_1F800000.view.effect.params[2] = phase << 6;
        prim->x2                         = D_1F800000.view.effect.params[3] + FIXED_MUL(rsin(phase << 6), D_1F800000.view.effect.params[0]);
        prim->y2                         = D_1F800000.view.effect.params[4] + FIXED_MUL(rcos(D_1F800000.view.effect.params[2]), D_1F800000.view.effect.params[0]);
        setRGB0(prim, 1, 1, 0xC0);
        setRGB1(prim, 0xE0, 0xE0, 0xE0);
        setRGB2(prim, 0xE0, 0xE0, 0xE0);
        GFX_AddPrim(3, sizeof(POLY_G3));
    }
}

INCLUDE_ASM(func_801EF750);

INCLUDE_ASM(func_801EF9E0);

/* func_801EFCA0 */
#include "overlays/bmagic/BMagic_AllocEffect.h"

/* func_801EFD04 */
#include "overlays/bmagic/Actor_Clear.h"
