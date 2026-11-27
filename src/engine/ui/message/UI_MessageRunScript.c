#include "engine/slus/slus.h"

/* The channel record at g_UIWindowChannel is addressed by byte offsets from its flag halfword: +0 flags, +2 a result
 * byte, +3 a repeat count, +0xC the script cursor, +0x10 the return cursor. */
#define CHAN_CURSOR(base) (*(u8**)((base) + 0xC))
#define CHAN_RETURN(base) (*(u8**)((base) + 0x10))
#define CHAN_FLAGS(base)  (*(u16*)(base))
#define CHAN_STATE(base)  ((base)[-4])

/* runs the channel script at the cursor until an opcode ends the step: 0 returns or ends the step in state 2, 2 ends
 * it in state 3, 3/4/7/8 call a sub-script (with its return cursor kept), 0xA queues a cue, 0xB ends the step in
 * state 1, 0xF/0x14/0x16 load per-channel fields, 0x10/0x11 toggle bit 0x10; other opcodes read the pad state.
 */
/* func_8015083C */
#ifdef NON_MATCHING
NON_MATCHING void UI_MessageRunScript(void) {
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
    u8*  cur16;
    u8*  cur14;
    u8*  curF;
    u8*  base8;
    u8   entry;
    u8   hi;
    s32  idx7;
    u8*  next7;
    u8*  next4;
    s32  idx;

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
        switch (*(u8*)g_UIMessageState.cursor) {
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
                SND_SEPlay(*(u8*)g_UIMessageState.cursor | 0x200);
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
                cur16             = *(u8**)(s4 + 0xA);
                loop              = 0;
                *(u8**)(s4 + 0xA) = cur16 + 1;
                s4[0]             = cur16[1];
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
                cur14              = *(u8**)(s2 - 0x14);
                *(u8**)(s2 - 0x14) = cur14 + 1;
                count              = cur14[1];
                *(u8**)(s2 - 0x14) = cur14 + 3;
                p                  = (u8*)g_UIMessageState.cursor;
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
                idx7              = *(u8*)g_UIMessageState.cursor;
                chan[3]           = 0x21;
                CHAN_CURSOR(chan) = (u8*)&D_801490D7 + (idx7 << 5);
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
                idx               = *(u8*)g_UIMessageState.cursor;
                chan[3]           = 6;
                CHAN_CURSOR(chan) = (u8*)&D_80144967 + idx * PARTY_RECORD_STRIDE;
                break;
            case 0xF:
                curF               = *(u8**)(s3 + 0xE);
                *(u8**)(s3 + 0xE)  = curF + 1;
                p                  = (u8*)g_UIMessageState.cursor;
                entry              = D_8017F5B8[curF[1]].unk_00;
                s3[1]              = 0;
                s3[-1]             = 0;
                s3[0]              = entry;
                *(u16*)(s3 + 8)    = D_8017F5B8[*p].unk_02;
                *(s16*)(s3 + 0x26) = (s8)D_8017F5B8[*p].unk_01;
                break;
            case 5:
            case 0xC:
                *s5 += 1;
                break;
            case 8:
                CHAN_FLAGS(chan) |= FRONTEND_FLAG_TIMER_ACTIVE;
                base8 = (u8*)D_80010004;
                CHAN_CURSOR(chan) += 1;
                CHAN_RETURN(chan) = CHAN_CURSOR(chan);
                v                 = *(u8*)g_UIMessageState.cursor;
                base8 += SLUS_LOAD_ADDRESS;
                CHAN_CURSOR(chan) = base8;
                CHAN_CURSOR(chan) = base8 + *(u16*)((u8*)g_UIMessageState.cursor + v * 2);
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
#else
INCLUDE_ASM(UI_MessageRunScript);
#endif
