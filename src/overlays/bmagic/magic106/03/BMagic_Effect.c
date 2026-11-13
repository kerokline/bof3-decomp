#include "magic106_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    PartyMember* saved;
    PartyMember* swap;
    s32          count;

    BMagic_DispatchTaskPair(func_801EECE4, Effect_PlayOnZeroTick);
    count = 0;
    do {
        if (D_801EF9F8[(u8)count << 5] & 0x1) {
            saved                 = g_BattleEffectBattler;
            swap                  = FIELD(PartyMember*, D_801EFA14, (u8)count << 5);
            g_BMagicOrbitWork     = D_801EF9F8 + ((u8)count << 5);
            g_BattleEffectBattler = swap;
            func_801EEEE0();
            g_BattleEffectBattler = saved;
        }
        count += 1;
    } while ((u8)count < 96);
}

MATCH void func_801EECE4(void) {
    PartyMember* work;
    u8           i;
    u32          row;
    u8           growth;
    u8           slot;

    for (i = 0; i < 96; i++) {
        D_801EF9F8[i << 5]       = 0;
        D_801EF9F8[(i << 5) + 1] = 0;
        D_801EF9F8[(i << 5) + 2] = 0;
    }
    work              = g_Task;
    work->pos.x.fixed = g_Battle.selected_actor->pos.x.fixed;
    /* FAKE: retail re-reads the selected actor for the next copy. */
    FAKE_BARRIER();
    work->pos.y.fixed = g_Battle.selected_actor->pos.y.fixed;
    /* FAKE: retail re-reads the selected actor for the next copy. */
    FAKE_BARRIER();
    work->pos.z.fixed  = g_Battle.selected_actor->pos.z.fixed + 0x1000000;
    work->param.unk_0B = 0;
    g_Task->unk_09     = 0;
    g_Task->header.mode += 1;
    for (i = 0; i < 96; i++) {
        slot                                 = func_801EF914();
        row                                  = slot << 5;
        FIELD(PartyMember*, D_801EFA14, row) = g_Task;
        D_801EF9F8[row + 1]                  = 0;
        D_801EF9F8[row + 4]                  = i;
        growth                               = ((i >> 1) & 0x70) + (rand() & 0xF) + 1;
        D_801EF9F8[row + 10]                 = growth;
        D_801EF9F8[row + 8]                  = 0x40 - growth;
        g_Task->param.unk_0B += 1;
    }
    SND_QueueSelectionFx(0x100);
    SND_QueueSelectionFx(0x101);
}

#include "overlays/bmagic/Effect_PlayOnZeroTick.h"

MATCH void func_801EEEE0(void) {
    BMagicOrbitWork* work;

    work = g_BMagicOrbitWork;
    D_801EF9C0[work->header.mode]();
}

MATCH void func_801EEF24(void) {
    SYS_DISPATCH_BYTE(D_801EF9C4, g_BMagicOrbitWork->header.step);
    if (g_BMagicOrbitWork->header.flags != 0 && g_BMagicOrbitWork->header.step != 0) {
        func_801EF52C();
        func_801EF5F4();
        PopMatrix();
    }
}

/* func_801EEFAC */
#include "overlays/bmagic/Effect_StartOrbit.h"

MATCH void func_801EF16C(void) {
    s32 threshold;

    g_BMagicOrbitWork->radius -= 2;
    g_BMagicOrbitWork->pos.x.fixed = g_BattleEffectBattler->pos.x.fixed + rsin((s16)g_BMagicOrbitWork->angle) * g_BMagicOrbitWork->radius;
    g_BMagicOrbitWork->pos.y.fixed = g_BattleEffectBattler->pos.y.fixed + rcos((s16)g_BMagicOrbitWork->angle) * g_BMagicOrbitWork->radius;
    g_BMagicOrbitWork->unk_0B++;
    if (g_BMagicOrbitWork->unk_09 < 16) {
        g_BMagicOrbitWork->unk_09 += 2;
    }
    threshold = ((g_BMagicOrbitWork->unk_04 >> 5) * 8) + 0x20;
    if (g_BMagicOrbitWork->radius <= threshold) {
        g_BMagicOrbitWork->header.step++;
        if (g_BMagicOrbitWork->unk_04 == 0) {
            Battle_ApplyDamageFlags(g_Battle.target_selector, 0x10);
        }
    }
}

/* func_801EF29C */
#include "overlays/bmagic/Effect_StepOrbit.h"

MATCH void func_801EF418(void) {
    BMAGIC_ORBIT_BATTLER_AND_CLEAR(func_801EF970);
}

MATCH void func_801EF52C(void) {
    SVECTOR pos;
    SVECTOR rot;
    MATRIX  matrix;
    long    flags;
    s32     off;

    PushMatrix();
    rot.vx = 0;
    rot.vy = 0;
    off    = g_BMagicOrbitWork->angle + 0x800;
    rot.vz = ((g_BMagicOrbitWork->unk_03 << 7) - off) & 0xFFF;
    pos.vx = (g_BMagicOrbitWork->pos.x.fixed >> 9) - 0x4000;
    pos.vy = (g_BMagicOrbitWork->pos.y.fixed >> 9) - 0x4000;
    pos.vz = -COORD_INT(g_BMagicOrbitWork->pos.z) / 2;
    RotTransMatrix(&pos, matrix, &flags);
    Camera_SetModelMatrix(&rot, &matrix);
}

INCLUDE_ASM(func_801EF5F4);

MATCH u32 func_801EF914(void) {
    u8 index;

    for (index = 0u; index < 96; index++) {
        if ((D_801EF9F8[index << 5] & 0x1) == 0) {
            D_801EF9F8[index << 5] |= 1;
            return index;
        }
    }
    return 0xFFu;
}

MATCH void func_801EF970(void) {
    g_BMagicOrbitWork->header.flags = 0;
    g_BMagicOrbitWork->header.mode  = 0;
    g_BMagicOrbitWork->header.step  = 0;
    g_BMagicOrbitWork->unk_03       = 0;
    g_BMagicOrbitWork->unk_04       = 0;
}
