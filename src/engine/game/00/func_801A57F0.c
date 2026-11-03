#include "game_00.h"

/* Entity spawn counter in scratchpad (signed 16-bit slot index). */

/* Packed spawn record staging halfword in scratchpad. */

/* Parallel per-slot shadow tables overlaying the 0x98-byte work-area
 * records; each column stores one field of every slot at a fixed address.
 * The scalars D_801468FF, D_80146914 and D_80146916 are columns too,
 * addressed through byte offsets because the headers declare them as scalars. */

MATCH void func_801A57F0(u8* script) {
    s16*   counter = (s16*)&D_1F800000;
    s32    coord_x;
    s32    coord_y;
    s16    slot;
    Actor* work;

    slot = *counter;
    if (slot >= ENTITY_MAX) {
        return;
    }

    g_SpadWork         = &g_Actors[slot];
    GAME_WORK_AREA_PTR = &g_Actors[slot];

    D_1F800002 = (u16)((script[1] << 8) | script[2]);

    func_801A4AA8();
    Area_FindSceneRecord(D_1F800002);

    g_SpadWork->flags_00 = ACTOR_FLAG_IN_USE;

    /* The outer shadow assignment forms the slot offset before the position
     * flag test, as retail schedules it. */
    work                    = g_SpadWork;
    D_80146908[*counter][0] = work->x.fixed = (script[7] << 16) | (script[6] != 0 ? 0x8000 : 0);
    /* FAKE: forces the counter re-read before the next shadow store. */
    MATCH_BARRIER();

    D_8014690C[*counter][0] = work->y.fixed = (script[9] << 16) | (script[8] != 0 ? 0x8000 : 0);
    /* FAKE: forces the counter re-read before the next shadow store. */
    MATCH_BARRIER();

    D_80146910[*counter][0] = 0;

    g_SpadWork->z.part.integer = Area_SampleHeight(work->x.fixed, work->y.fixed);
    g_SpadWork->unk_01         = script[0xA];
    g_SpadWork->state_02       = script[0xC];
    g_SpadWork->unk_18         = script[0x11];
    g_SpadWork->unk_1C         = script[0x12];
    g_SpadWork->direction_08   = script[0] & 0xF;
    g_SpadWork->unk_06         = script[0] >> 4;

    *(u16*)((u8*)&D_80146914 + *counter * ACTOR_SIZE) = script[4];
    *(s16*)((u8*)&D_80146916 + *counter * ACTOR_SIZE) = script[5];
    D_80146904[*counter][0]                           = (u16)(script[0xF] | (script[0xE] << 8));
    /* FAKE: forces the counter re-read before the next shadow store. */
    MATCH_BARRIER();
    D_80146900[*counter][0]                          = script[0xB];
    *(u8*)((u8*)&D_801468FF + *counter * ACTOR_SIZE) = script[0x10];
    D_8014691C[*counter][0]                          = 0x7F;

    func_801A4990(script + 0xD);

    if (script[3] & 0x80) {
        g_SpadWork->flags_00 |= ACTOR_FLAG_SEMI_TRANSPARENT;
    }

    g_SpadWork->tint.bytes.unk_5D = 0;
    g_SpadWork->tint.bytes.unk_5F = 0;
    g_SpadWork->tint.bytes.unk_5E = 0;
    g_SpadWork->tint.bytes.flags  = script[3] & 0xF;

    func_801A4914();

    (VOL(u16, D_1F800000)) = (VOL(u16, D_1F800000)) + 1;
}
