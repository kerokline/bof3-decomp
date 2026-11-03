#include "game_00.h"

MATCH void func_8019E2A8(void) {
    Actor* work;
    Actor* state;
    Actor* other;
    Actor* flags;

    Area_FindSceneRecord(0x18);
    g_SpadWork->flags_24                 = 0;
    g_SpadWork->unk_2A                   = 0;
    work                                 = g_SpadWork;
    work->unk_2B                         = (u8)(work->unk_2B + 1);
    g_SpadWork->unk_48                   = 0;
    state                                = g_SpadWork;
    state->tint.signed_bytes.unk_5D      = 0;
    other                                = g_SpadWork;
    state->vz                            = 0x40;
    state->gravity                       = -8;
    other->tint.signed_bytes.unk_5E      = 0;
    g_SpadWork->tint.signed_bytes.unk_5F = 0;
    Actor_SelectScript(8);
    flags           = g_SpadWork;
    flags->state_02 = (u8)(flags->state_02 + 1);
}
