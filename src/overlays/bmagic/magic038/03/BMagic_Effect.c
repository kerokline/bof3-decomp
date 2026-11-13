#include "magic038_03.h"

#if BOF3_USE_ASM
__asm__(".include \"include/match/macro.inc\"\n");
#endif

#include "overlays/bmagic/BMagic_DispatchMode.h"

MATCH void func_801EEC70(void) {
    u16          i;
    u8           slot;
    PartyMember* task;
    PartyMember* work;
    u16*         dst;
    u16*         src;
    u16*         row_dst;
    u16*         row_src;

    Battle_CenterCamera();
    task               = g_Task;
    task->param.unk_0B = 0;
    task->pos.z.fixed += 0x2000000;
    g_Task->unk_09 = 0;
    g_Task->header.mode += 1;
    for (i = 0; i < 16; i++) {
        slot                               = Battle_AllocEffect(1, 89);
        work                               = g_Task;
        g_BattleEffects[slot].header.mode  = 0;
        g_BattleEffects[slot].unk_0B       = i;
        g_BattleEffects[slot].arg.unk_09   = i * 8 + 1;
        g_BattleEffects[slot].target.party = work;
        g_Task->param.unk_0B += 1;
    }
    /* Copies the first two CLUTs of arena palette row 26 into the work copy as they are, then row 2 with STP set. */
    i   = 0;
    dst = MEM_PTR(u16, AREA_PALETTE_WORK + 26 * AREA_PALETTE_ROW);
    src = MEM_PTR(u16, AREA_PALETTE_ARENA + 26 * AREA_PALETTE_ROW);
    for (; i < 16; i++) {
        dst[i]      = src[i];
        dst[i + 16] = src[i + 16];
    }
    i       = 0;
    row_dst = MEM_PTR(u16, AREA_PALETTE_WORK + 2 * AREA_PALETTE_ROW);
    row_src = MEM_PTR(u16, AREA_PALETTE_ARENA_33C00);
    for (; i < 16; i++) {
        row_dst[i] = row_src[i] | 0x8000;
    }
    *MEM_PTR(u16, AREA_PALETTE_WORK + 2 * AREA_PALETTE_ROW) = *MEM_PTR(u16, AREA_PALETTE_ARENA_33C00);
    g_GfxPalettePending                                     = 1;
    SND_QueueSelectionFx(EMI_CUE_ID(SND_BANK_COMMON, 0));
}

INCLUDE_ASM(func_801EEE14);

#include "overlays/bmagic/Effect_StartOnZeroTick.h"

/* func_801EF0D0 */
#include "overlays/bmagic/BMagic_DispatchEffectMode.h"

MATCH void func_801EF114(void) {
    g_ScriptTable = BMAGIC_SCRIPT_TABLE;
    SYS_DISPATCH_BYTE(D_801EF9A8 + 1, g_Task->header.step);
    if (g_Task->header.flags != 0 && g_Task->header.step != 0) {
        func_8014D290();
    }
    g_ScriptTable = AREA_SCRIPT_TABLE;
}

INCLUDE_ASM(func_801EF1AC);

INCLUDE_ASM(func_801EF3BC);

INCLUDE_ASM(func_801EF590);

INCLUDE_ASM(func_801EF710);

#include "overlays/bmagic/Effect_TickDownAndClear.h"

MATCH void func_801EF8B8(void) {
    SYS_DISPATCH_TASK((g_BMagicEffectModes + 11), 2, g_Task);
}

#include "overlays/bmagic/Effect_QueueEntry.h"

#include "overlays/bmagic/Effect_TickOnZeroTick.h"
