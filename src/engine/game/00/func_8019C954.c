#include "game_00.h"

MATCH void func_8019C954(void) {
    Actor* record;
    s32    index;
    s16    counter;

    index = D_80145E9B;
    g_SpadWork->flags_00 |= ACTOR_FLAG_SKIP_PALETTE_STAGE;
    g_SpadWork->flags_24 = 1;
    record               = (Actor*)&g_ActorSlots[index];
    g_SpadWork->unk_2C   = record->unk_2C;
    g_SpadWork->unk_27   = 0x7B;
    g_SpadWork->unk_28   = 2;
    g_SpadWork->unk_25   = 0x1D;
    g_SpadWork->unk_26   = 0;
    g_SpadWork->unk_4C   = record->unk_4C;
    g_SpadWork->unk_2B   = 1;
    g_SpadWork->unk_29   = record->unk_29;
    g_SpadWork->unk_48   = 0;
    {
        u8* work;
        u8* next;

        work                    = (u8*)g_SpadWork;
        FIELD(s32, work, 0x34u) = record->x.fixed;
        FIELD(s32, work, 0x38u) = record->y.fixed;
        counter                 = record->z.part.integer;
        work[0x5D]              = 0;
        next                    = (u8*)g_SpadWork;
        FIELD(s16, work, 0x3Eu) = counter;
        next[0x5E]              = 0;
    }
    g_SpadWork->tint.bytes.unk_5F = 0;
    g_SpadWork->tint.bytes.flags  = 0;
    Actor_SelectScript(0x4E);
    g_SpadWork->unk_01 = 2;
}
