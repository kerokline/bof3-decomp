#include "magic114_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC44(void) {
    Callback handlers[7];
    s32      tpage;

    __builtin_memcpy(handlers, D_801EEC04, sizeof(handlers));
    if (GetGraphType() == 1) {
        tpage = 0xA5;
    } else if (GetGraphType() == 2) {
        tpage = 0xA5;
    } else {
        tpage = 0x35;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));
    if (g_Task->header.flags != 0 && g_Task->header.mode != 0) {
        func_801EF128();
    }
    SYS_DISPATCH_BYTE(handlers, g_Task->header.mode);
    if (GetGraphType() == 1) {
        tpage = 0xA5;
    } else if (GetGraphType() == 2) {
        tpage = 0xA5;
    } else {
        tpage = 0x35;
    }
    SetDrawMode((DR_MODE*)g_GfxPrimCursor, 0, 1, tpage, 0);
    GFX_AddPrim(3, sizeof(DR_MODE));
}

INCLUDE_ASM(func_801EEDA0);

MATCH void func_801EEE84(void) {
    u8 count;

    count         = g_Task->timer + 1;
    g_Task->timer = count;
    if ((count & BYTE_MASK) >= 0x21U) {
        g_Task->header.mode += 1;
        g_Task->unk_09 = 0;
    }
}

MATCH void func_801EEEE4(void) {
    u8 count;

    count          = g_Task->unk_09 + 1;
    g_Task->unk_09 = count;
    if ((count & BYTE_MASK) >= 0x21U) {
        g_Task->header.mode += 1;
        g_Task->unk_09 = 0;
    }
}

MATCH void func_801EEF44(void) {
    u8  count;
    u32 slot;

    count          = g_Task->unk_09 + 1;
    g_Task->unk_09 = count;
    if ((count & BYTE_MASK) < 0x20U) {
        return;
    }
    g_Task->header.mode += 1;
    SND_QueueSelectionFx(EMI_CUE_ID(SND_BANK_COMMON, 0x01));
    slot                               = Battle_AllocEffect(1, 7) & BYTE_MASK;
    g_BattleEffects[slot].header.mode  = 0;
    g_BattleEffects[slot].unk_08       = g_BattleEffectBattler->facing;
    g_BattleEffects[slot].target.party = g_BattleEffectBattler;
}

MATCH void func_801EEFFC(void) {
    u8 count;

    count          = g_Task->unk_09 - 1;
    g_Task->unk_09 = count;
    if (!(count & BYTE_MASK)) {
        g_Task->header.mode += 1;
        return;
    }
    func_801F0FBC();
}

MATCH void func_801EF060(void) {
    u8 count;

    count         = g_Task->timer - 1;
    g_Task->timer = count;
    if (!(count & BYTE_MASK)) {
        g_Task->header.mode += 1;
        g_Task->unk_09 = 0x40;
    }
}

#include "overlays/bmagic/Effect_CountDownAndPlay.h"

MATCH void func_801EF128(void) {
    s32 values[8];
    s32 pos_x;
    s32 pos_y;
    u8* prim;
    u32 i;
    u32 row;

    func_801EF6A8();
    prim = g_GfxPrimCursor;
    i    = 0;
    do {
        row            = i & 3;
        g_Task->unk_0C = D_801F11F4[row][0] * g_Task->timer;
        g_Task->unk_10 = D_801F11F4[row][1] * g_Task->timer;
        func_801DD350(g_Task);
        g_Task->pos.x.fixed = g_Task->unk_0C;
        g_Task->pos.y.fixed = g_Task->unk_10;
        g_Task->unk_0C      = D_801F11F4[row + 1][0] * g_Task->timer;
        g_Task->unk_10      = D_801F11F4[row + 1][1] * g_Task->timer;
        func_801DD350(g_Task);
        g_Task->param.unk_0B = i;
        func_801EF280(values);
        i++;
    } while (i < 8);
    pos_x = g_BattleEffectBattler->pos.x.fixed;
    pos_y = g_BattleEffectBattler->pos.y.fixed;
    func_800AF0F8(pos_x, pos_y, values, prim, 8, 0x1C, 2);
    PopMatrix();
}

INCLUDE_ASM(func_801EF280);

MATCH void func_801EF6A8(void) {
    PartyMember* src;
    SVECTOR      pos;
    SVECTOR      rot;
    MATRIX       matrix;
    long         flags;

    PushMatrix();
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = ((g_Task->timer & 0x1F) - 2) << 7;
    src    = (PartyMember*)g_BattleEffectBattler;
    pos.vx = (src->pos.x.fixed >> 9) - 0x4000;
    pos.vy = (src->pos.y.fixed >> 9) - 0x4000;
    pos.vz = -(COORD_INT(src->pos.z) + 0x200) / 2;
    RotTransMatrix(&pos, matrix, &flags);
    Camera_SetModelMatrix(&rot, &matrix);
}

/* func_801EF774 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EF7B8(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 3), 2, g_Task);
}

INCLUDE_ASM(func_801EF7FC);

MATCH void func_801EF8C0(void) {
    u8 slot;
    u8 count;

    func_801EFA80();
    slot                                   = Battle_AllocEffect(1, 7);
    g_BattleEffects[slot].target.party     = g_BattleEffectBattler;
    g_BattleEffects[slot].header.mode      = 2;
    g_BattleEffects[slot].unk_08           = g_BattleEffectBattler->facing;
    g_BattleEffects[slot].pos.x.fixed      = g_AreaScrollTargetX + g_Task->unk_0C;
    g_BattleEffects[slot].pos.y.fixed      = g_AreaScrollTargetY + g_Task->unk_10;
    COORD_INT(g_BattleEffects[slot].pos.z) = g_Task->unk_14;
    if (g_Task->unk_09 == 0) {
        slot                                   = Battle_AllocEffect(1, 7);
        g_BattleEffects[slot].header.mode      = 1;
        g_BattleEffects[slot].target.party     = g_BattleEffectBattler;
        g_BattleEffects[slot].unk_08           = g_Task->facing;
        g_BattleEffects[slot].unk_0C           = g_Task->unk_0C;
        g_BattleEffects[slot].unk_10           = g_Task->unk_10;
        COORD_INT(g_BattleEffects[slot].pos.z) = g_Task->unk_14;
        g_BattleEffects[slot].arg.unk_09       = 0x10;
        g_BattleEffects[slot].unk_0B           = 0;
    }
    count          = g_Task->unk_09 + 1;
    g_Task->unk_09 = count;
    if (count >= 13) {
        func_801E5988();
    }
}

INCLUDE_ASM(func_801EFA80);

MATCH void func_801EFDD8(void) {
    SYS_DISPATCH_BYTE(D_801F1230, g_Task->header.step);
    if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
        func_801F093C();
        func_801F04D4(g_Task->param.unk_0B);
        func_801F0004();
    }
}

INCLUDE_ASM(func_801EFE70);

MATCH void func_801EFF1C(void) {
    s32 value;

    g_Task->unk_20 -= 5;
    if (g_Task->unk_14 == 0x30) {
        Battle_ApplyDamageFlags(g_Battle.target_selector, 0x10U);
    }
    value          = g_Task->unk_14 + 2;
    g_Task->unk_14 = value;
    if (value == 0xC0) {
        g_Task->param.unk_0B = 1;
        g_Task->header.step += 1;
    }
}

MATCH void func_801EFFB0(void) {
    PartyMember* work  = g_Task;
    u8           timer = work->unk_09 - 1;
    work->unk_09       = timer;
    work->unk_20 -= 5;
    work->unk_14 += 2;
    if (timer == 0) {
        func_801E5988();
    }
}

INCLUDE_ASM(func_801F0004);

INCLUDE_ASM(func_801F04D4);

INCLUDE_ASM(func_801F093C);

MATCH void func_801F0D08(void) {
    g_ScriptTable = BMAGIC_SCRIPT_TABLE;
    SYS_DISPATCH_BYTE(D_801F1230 + 3, g_Task->header.step);
    g_ScriptTable = AREA_SCRIPT_TABLE;
}

MATCH void func_801F0D6C(void) {
    PartyMember* work;

    g_Task->unk_25    = 0x1D;
    g_Task->unk_26    = 0;
    g_Task->unk_27    = 0x1A;
    g_Task->unk_28    = 1;
    g_Task->unk_2A    = (g_Task->facing - 0x1) & 1;
    g_Task->unk_29    = 4;
    g_Task->unk_24    = 0;
    work              = g_Task;
    work->unk_2B      = 0;
    work->unk_2C.half = 0;
    g_Task->unk_09    = 0;
    g_Task->header.step += 1;
    Actor_SelectScript(0);
    func_8014D290();
}

MATCH void func_801F0E4C(void) {
    if (Actor_StepAnimOnce() & BYTE_MASK) {
        func_801E5988();
        return;
    }
    func_8014D290();
}

MATCH void func_801F0E90(void) {
    SVECTOR      pos;
    SVECTOR      rot;
    MATRIX       matrix;
    long         flags;
    PartyMember* battler;
    PartyMember* work;

    PushMatrix();
    if (g_Task->facing & 1) {
        rot.vx = 0x400;
        rot.vy = 0;
    } else {
        rot.vx = 0;
        rot.vy = 0x400;
    }
    rot.vz         = 0;
    g_Task->unk_0C = 0xC000;
    g_Task->unk_10 = 0;
    func_801DD350(g_Task);
    battler                = g_BattleEffectBattler;
    work                   = g_Task;
    work->pos.x.fixed      = battler->pos.x.fixed + work->unk_0C;
    work->pos.y.fixed      = battler->pos.y.fixed + work->unk_10;
    COORD_INT(work->pos.z) = COORD_INT(battler->pos.z) + 0x200;
    pos.vx                 = (work->pos.x.fixed >> 9) - 0x4000;
    pos.vy                 = (work->pos.y.fixed >> 9) - 0x4000;
    pos.vz                 = -COORD_INT(work->pos.z) / 2;
    RotTrans(&pos, (VECTOR*)matrix.t, &flags);
    RotMatrix(&rot, &matrix);
    MulMatrix2(&g_CameraMatrix, &matrix);
    SetRotMatrix(&matrix);
    SetTransMatrix(&matrix);
}

INCLUDE_ASM(func_801F0FBC);
