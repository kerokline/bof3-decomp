#include "area108_14.h"

MATCH void func_801F4B58(void) {
    Actor* flags_set;
    Actor* flags_clear;
    Actor* tint;

    g_CurrentActor->unk_93 = GFX_AllocPaletteFade(SP_REF(u8*, 0x44u), 0U, 0U, 0U, 1);
    flags_set              = g_SpadWork;
    flags_set->flags_00 |= 0x20;
    flags_clear = g_SpadWork;
    flags_clear->flags_00 &= 0xBF;
    g_SpadWork->tint.bytes.flags   = 1;
    tint                           = g_SpadWork;
    tint->tint.signed_bytes.unk_5F = -0x80;
    tint->tint.signed_bytes.unk_5E = -0x80;
    tint->tint.signed_bytes.unk_5D = -0x80;
    g_SpadWork->unk_04             = 1;
    g_CurrentActor->unk_7E         = (u16)(g_CurrentActor->unk_7E - 2);
}
