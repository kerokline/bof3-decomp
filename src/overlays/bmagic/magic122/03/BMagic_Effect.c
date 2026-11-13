#include "magic122_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

MATCH void func_801EEC04(void) {
    Callback handlers[2] = {func_801EEC5C, func_801EEDFC};
    SYS_DISPATCH_TASK(handlers, 1, g_Task);
}

MATCH void func_801EEC5C(void) {
    PartyMember* battler;
    PartyMember* task;
    PartyMember* owner;
    u16*         dst;
    u16*         src;
    u16*         dst2;
    u16*         src2;
    u16*         dst3;
    u16*         src3;
    u32          slot;
    u32          i;

    g_Task->facing = g_BattleEffectBattler->facing;
    battler        = g_BattleEffectBattler;
    task           = g_Task;
    WorldPos_Copy(&task->pos, &battler->pos);
    slot                               = Battle_AllocEffect(1, 56) & BYTE_MASK;
    owner                              = g_Task;
    g_BattleEffects[slot].header.mode  = 0;
    g_BattleEffects[slot].arg.unk_09   = 4;
    g_BattleEffects[slot].target.party = owner;
    i                                  = 1;
    dst                                = &MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[1];
    src                                = &MEM_PTR(u16, AREA_PALETTE_ARENA + 26 * AREA_PALETTE_ROW)[1];
    for (; i < 16; i++) {
        *dst++ = *src++ | 0x8000;
    }
    i    = 1;
    src2 = &MEM_PTR(u16, AREA_PALETTE_ARENA + 26 * AREA_PALETTE_ROW)[1];
    dst2 = &MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[1];
    for (; i < 16; i++) {
        dst2[16] = src2[16];
        dst2++;
        src2++;
    }
    i    = 1;
    src3 = &MEM_PTR(u16, AREA_PALETTE_ARENA + 26 * AREA_PALETTE_ROW)[1];
    dst3 = &MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[1];
    for (; i < 16; i++) {
        dst3[32] = src3[32] | 0x8000;
        dst3++;
        src3++;
    }
    MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[0]  = 0;
    MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[16] = 0;
    MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW)[32] = 0;
    g_GfxPalettePending                                         = 1;
    g_Task->param.unk_0B                                        = 0;
    g_Task->unk_09                                              = 0;
    g_Task->header.mode++;
}

#include "overlays/bmagic/Effect_PlayOnIdleTick.h"

/* func_801EEE5C */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EEEA0(void) {
    SYS_DISPATCH_BYTE(D_801F02D0, g_Task->header.step);
    if (g_BattleEffectBattler->param.unk_0B != 0xFF) {
        if (g_Task->header.step != 0) {
            func_801EFBA8();
            func_801EF324();
        }
    }
}

INCLUDE_ASM(func_801EEF2C);

MATCH void func_801EF158(void) {
    PartyMember* work;

    work = g_Task;
    work->timer += 3;
    work = g_Task;
    work->unk_09++;
    if (work->unk_09 == 8) {
        work = g_Task;
        work->header.step++;
    }
}

#include "overlays/bmagic/Effect_CountUpTimerCallSelector.h"

#include "overlays/bmagic/Effect_CountUpAndStepAt120.h"

#include "overlays/bmagic/Effect_CountUpAndFinishAt136.h"

INCLUDE_ASM(func_801EF324);

INCLUDE_ASM(func_801EFBA8);
