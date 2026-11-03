#include "game_00.h"

MATCH s8 func_801BDE14(s32 pos_x, s32 pos_y, s32 range_mode) {
    /* FAKE: MATCH_REG pins kind to s4: gcc-2.7.2 allocates the call result
     * to s2 by live-length, but the original holds it in s4 (args in s2/s3/s5).
     */
    MATCH_REG(s16, kind, "s4");
    /* FAKE: MATCH_REG pins the pos_x/pos_y copies; each is materialised by its own
     * statement opening the guarded body, so the loop-entry bnez takes the a1
     * copy into its delay slot and gcc emits the pos_x copy (and only then the
     * a2 sign-extension) in retail's order. Without the pins gcc fills the slot
     * with `sll a2,s4,0x10` and orders the setup differently. */
    MATCH_REG(s32, a1v, "a1");
    MATCH_REG(s32, a0v, "a0");
    /* FAKE: MATCH_REG pins the pos_y copy to a1 and the copy is materialised by its
     * own statement in the loop body; the delay slot of the loop-entry bnez then
     * takes that copy, retail's slot content (without it gcc speculates the
     * sign-extension `sll a2,s4,0x10` into the slot). The call reads the pinned
     * local, so the register setup still carries exactly one copy. */
    s32 index;
    s32 off;
    u8* slot;

    kind  = func_801BDCF8();
    index = 0;
    off   = 0;
    do {
        slot = (u8*)g_Actors + off;
        if ((slot != (u8*)SCRATCH_WORK) && (((u8*)g_Actors)[off] != 0) && ((((u8*)g_Actors + 7)[off] & 0x80) == 0)) {
            a1v = pos_y;
            a0v = pos_x;
            if (((func_801BDD58(a0v, a1v, kind, range_mode, (Actor*)slot)) & BYTE_MASK) != 0) {
                return index;
            }
        }
        index += 1;
        off += ACTOR_SIZE;
    } while (index < 34);
    return -1;
}
