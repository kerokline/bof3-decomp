#include "engine/slus/slus.h"

/* The channel record at g_UIWindowChannel is addressed by byte offsets from its flag halfword: +0 flags, +2 a result
 * byte, +3 a repeat count, +0xC the script cursor, +0x10 the return cursor. */
#define CHAN_CURSOR(base)  (*(u8**)((base) + 0xC))
#define CHAN_RETURN(base)  (*(u8**)((base) + 0x10))
#define CHAN_FLAGS(base)   (*(u16*)(base))
#define CHAN_STATE(base)   ((base)[-4])
/* the halfword at a byte offset from a script or channel byte pointer */
#define HALF_AT(base, off) (*(u16*)((base) + (off)))

/* runs the channel script at the cursor until an opcode ends the step: 0 returns or ends the step in state 2, 2 ends
 * it in state 3, 3/4/7/8 call a sub-script (with its return cursor kept), 0xA queues a cue, 0xB ends the step in
 * state 1, 0xF/0x14/0x16 load per-channel fields, 0x10/0x11 toggle bit 0x10; other opcodes read the pad state.
 */
/* func_8015083C */
MATCH void UI_MessageRunScript(void) {
    u8   loop;
    u8*  chan;
    u8*  s2;
    u8*  s3;
    u8*  s4;
    u8** s5;
    u8   count;
    s32  v;
    u16  flags;
    u8*  p;
    u8*  step_cursor;
    u8*  pair_cursor;
    u8*  entry_cursor;
    u8*  base8;
    u8   entry;
    u8   hi;
    s32  block;
    u8*  next7;
    u8*  next4;
    s32  idx;
    u16  timer_flags;

    loop = 1;
    chan = (u8*)&g_UIMessageState.flags;
    s5   = (u8**)(chan + 0xC);
    s4   = chan + 2;
    s2   = chan + 0x20;
    s3   = chan - 2;
    do {
        flags = CHAN_FLAGS(chan);
        if (flags & FRONTEND_FLAG_TIMER_ACTIVE) {
            if (--chan[3] == 0) {
                CHAN_FLAGS(chan)  = flags & ~FRONTEND_FLAG_TIMER_ACTIVE;
                CHAN_CURSOR(chan) = CHAN_RETURN(chan) + 1;
            }
        }
        switch (*g_UIMessageState.cursor) {
            case 1:
            case 6:
            case 9:
            case 0xD:
            case 0xE:
                break;
            case 0x100:
                CHAN_FLAGS(chan) |= 0x100;
                break;
            case 0xA:
                *s5 += 1;
                SND_SEPlay(*g_UIMessageState.cursor | 0x200);
                break;
            case 0:
                if (CHAN_FLAGS(chan) & FRONTEND_FLAG_TIMER_ACTIVE) {
                    CHAN_FLAGS(chan) &= ~FRONTEND_FLAG_TIMER_ACTIVE;
                    CHAN_CURSOR(chan) = CHAN_RETURN(chan);
                } else {
                    loop             = 0;
                    CHAN_STATE(chan) = 2;
                }
                break;
            case 0x16:
                step_cursor       = *(u8**)(s4 + 0xA);
                loop              = 0;
                *(u8**)(s4 + 0xA) = step_cursor + 1;
                s4[0]             = step_cursor[1];
                s4[-6]            = 7;
                break;
            case 0xB:
                loop   = 0;
                s4[-6] = 1;
                s4[0] += 8;
                break;
            case 2:
                g_UIMessageState.state = 3;
                loop                   = 0;
                break;
            case 0x14:
                pair_cursor        = *(u8**)(s2 - 0x14);
                *(u8**)(s2 - 0x14) = pair_cursor + 1;
                count              = pair_cursor[1];
                *(u8**)(s2 - 0x14) = pair_cursor + 3;
                p                  = g_UIMessageState.cursor;
                s2[0]              = count;
                s2[2]              = (*p & 0xF) - 1;
                loop               = 0;
                hi                 = *p >> 4;
                s2[1]              = hi;
                if (hi == 0) {
                    s2[-0x24] = 5;
                } else {
                    s2[-0x24] = 4;
                }
                break;
            case 7:
                loop              = 0;
                next7             = CHAN_CURSOR(chan) + 1;
                CHAN_CURSOR(chan) = next7;
                CHAN_FLAGS(chan) |= FRONTEND_FLAG_TIMER_ACTIVE;
                CHAN_RETURN(chan) = next7;
                block             = *g_UIMessageState.cursor;
                chan[3]           = 0x21;
                CHAN_CURSOR(chan) = (u8*)&D_801490D7 + (block << 5);
                break;
            case 3:
                CHAN_FLAGS(chan) |= FRONTEND_FLAG_TIMER_ACTIVE;
                CHAN_RETURN(chan) = CHAN_CURSOR(chan);
                idx               = g_CharSlot[g_Game.members[0].chr.character_id];
                loop              = 0;
                chan[3]           = 6;
                CHAN_CURSOR(chan) = (u8*)&D_80144967 + idx * PARTY_RECORD_STRIDE;
                break;
            case 4:
                loop              = 0;
                next4             = CHAN_CURSOR(chan) + 1;
                CHAN_CURSOR(chan) = next4;
                CHAN_FLAGS(chan) |= FRONTEND_FLAG_TIMER_ACTIVE;
                CHAN_RETURN(chan) = next4;
                idx               = *g_UIMessageState.cursor;
                chan[3]           = 6;
                CHAN_CURSOR(chan) = (u8*)&D_80144967 + idx * PARTY_RECORD_STRIDE;
                break;
            case 0xF:
                entry_cursor      = *(u8**)(s3 + 0xE);
                *(u8**)(s3 + 0xE) = entry_cursor + 1;
                p                 = g_UIMessageState.cursor;
                entry             = D_8017F5B8[entry_cursor[1]].unk_00;
                s3[1]             = 0;
                s3[-1]            = 0;
                s3[0]             = entry;
                HALF_AT(s3, 8)    = D_8017F5B8[*p].unk_02;
                HALF_AT(s3, 0x26) = (s8)D_8017F5B8[*p].unk_01;
                break;
            case 5:
            case 0xC:
                *s5 += 1;
                break;
            case 8:
                timer_flags = CHAN_FLAGS(chan);
                p           = CHAN_CURSOR(chan);
                base8       = (u8*)D_80010004;
                timer_flags |= FRONTEND_FLAG_TIMER_ACTIVE;
                p += 1;
                CHAN_FLAGS(chan)  = timer_flags;
                CHAN_CURSOR(chan) = p;
                CHAN_RETURN(chan) = p;
                v                 = *g_UIMessageState.cursor;
                base8 += SLUS_LOAD_ADDRESS;
                CHAN_CURSOR(chan) = base8;
                CHAN_CURSOR(chan) = base8 + HALF_AT(g_UIMessageState.cursor, v * 2);
                chan[3]           = 0x11;
                break;
            case 0x10:
            case 0x11:
                CHAN_FLAGS(chan) ^= FRONTEND_FLAG_NO_INPUT_WAIT;
                break;
            case 0x12:
            case 0x13:
            case 0x15:
                *s5 += 1;
                /* fallthrough */
            default:
                if (!(CHAN_FLAGS(chan) & FRONTEND_FLAG_NO_INPUT_WAIT)) {
                    if (g_PadStates[0].held & g_InputMasks[MESSAGE_INPUT_SPEED_UP]) {
                        chan[2] = D_8017F5B4[g_MessageSpeed];
                    } else {
                        chan[2] = D_8017F5B4[g_MessageSpeed + 1];
                    }
                    if (CHAN_FLAGS(chan) & FRONTEND_FLAG_FORCE_STEP) {
                        chan[2] = 3;
                    }
                    if (chan[2] == 0) {
                        CHAN_STATE(chan) = 0;
                    } else {
                        CHAN_STATE(chan) = 1;
                    }
                    loop = 0;
                }
                g_UIMessageState.index += 1;
                break;
        }
        if (CHAN_FLAGS(chan) & FRONTEND_FLAG_NO_INPUT_WAIT) {
            loop = 1;
        }
        CHAN_CURSOR(chan) += 1;
    } while (loop);
}
