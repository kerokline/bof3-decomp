#include "game_00.h"

MATCH void func_801B9210(void) {
    u8  saved;
    u8  mode;
    s32 v;

    if (g_SpadWork->tint.bytes.flags != 0) {
        GFX_StagePalette((u32)(GAME_PALETTE_STAGE + (g_SpadWork->unk_05 << 6)), 0);
        g_SpadWork->flags_00 &= ~ACTOR_FLAG_SEMI_TRANSPARENT;
        g_SpadWork->tint.bytes.flags  = 0;
        g_SpadWork->tint.bytes.unk_5D = 0;
        g_SpadWork->tint.bytes.unk_5E = 0;
        g_SpadWork->tint.bytes.unk_5F = 0;
    }
    g_SpadWork->flags_00 &= ~ACTOR_FLAG_HIDDEN;
    if ((g_SpadWork->x.fixed & 0x7FFF) != 0 || (g_SpadWork->y.fixed & 0x7FFF) != 0) {
        g_SpadWork->x.fixed = (g_SpadWork->x.fixed + 0x4800) & ~0x7FFF;
        g_SpadWork->y.fixed = (g_SpadWork->y.fixed + 0x4800) & ~0x7FFF;
        g_SpadWork->z.part.integer =
            Area_ReadStepHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed, g_SpadWork->direction_08);
        if (g_SpadWork->unk_05 == 0) {
            v                   = g_SpadWork->x.fixed;
            g_AreaScrollTargetX = v;
            v                   = g_SpadWork->y.fixed;
            g_AreaScrollTargetY = v;
            func_80153DE8();
        }
    }
    saved                    = g_SpadWork->direction_08;
    g_SpadWork->direction_08 = saved ^ 4;
    mode                     = (u8)func_801B9598();
    if (mode == 1 || mode == 3) {
        if ((func_801BDF08() << 24) != 0) {
            g_SpadWork->unk_09 = 0;
            Actor_ClearVelocity();
        } else {
            func_801C24D0();
            g_SpadWork->unk_09--;
            func_801C57B4();
        }
    } else {
        Actor_ClearVelocity();
    }
    func_801C2E34(g_SpadWork->unk_0B);
    g_SpadWork->direction_08 = saved;
    g_SpadWork->unk_0A       = 8;
    Actor_RequestScript(g_SpadWork->direction_08);
    SND_PlayCue(EMI_CUE_ID(1, 8));
    g_SpadWork->unk_03++;
}
