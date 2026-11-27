#include "game_00.h"

MATCH u8 func_801BC760(void) {
    PartyMember* member;
    PartyMember* state;
    PartyMember* saved;
    s32          lead_x;
    s32          lead_y;
    s32          tgt_x;
    s32          tgt_y;
    s32          near_x;
    s32          near_y;
    s32          cell_x;
    s32          cell_y;
    s32          span;
    s32          dx;
    s32          dy;
    s32          result;
    u8           dir;
    u8           count;

    dir    = SELF(Actor)->direction;
    lead_x = g_Game.members[0].pos.x.fixed + g_Game.members[0].unk_0C * g_Game.members[0].unk_09;
    lead_y = g_Game.members[0].pos.y.fixed + g_Game.members[0].unk_10 * g_Game.members[0].unk_09;
    if (g_Game.members[SELF(Actor)->unk_05 ^ 3].u.field.mode.unsigned_value != 9) {
        if (SELF(Actor)->unk_05 == 2) {
            if (g_Game.members[1].pad_06 != 0) {
                SELF(Actor)->unk_06 = 0;
            } else {
                SELF(Actor)->unk_06 = 1;
            }
        } else if (g_PartySize < 3) {
            SELF(Actor)->unk_06 = 0;
        } else {
            tgt_x = g_Game.members[2].pos.x.fixed + g_Game.members[2].unk_0C * g_Game.members[2].unk_09;
            tgt_y = g_Game.members[2].pos.y.fixed + g_Game.members[2].unk_10 * g_Game.members[2].unk_09;
            dx    = abs(SELF(Actor)->pos.x.fixed - lead_x) + abs(SELF(Actor)->pos.y.fixed - lead_y);
            dy    = abs(tgt_x - lead_x) + abs(tgt_y - lead_y);
            if (dy < dx) {
                SELF(Actor)->unk_06 = 2;
            } else {
                SELF(Actor)->unk_06 = 0;
            }
        }
    }
    member = &g_Game.members[SELF(Actor)->unk_06];
    tgt_x  = member->pos.x.fixed + member->unk_0C * member->unk_09;
    tgt_y  = member->pos.y.fixed + member->unk_10 * member->unk_09;
    span   = TO_COORD(1) + COORD_HALF;
    near_x = tgt_x - g_FacingSteps[member->facing].x * 2;
    near_y = tgt_y - g_FacingSteps[member->facing].y * 2;
    if (member->speed != 0) {
        span = TO_COORD(2);
    }
    if (abs(SELF(Actor)->pos.x.fixed - tgt_x) <= span && abs(SELF(Actor)->pos.y.fixed - tgt_y) <= span) {
        return 1;
    }
    func_801BCD60(near_x, near_y);
    dx = abs(SELF(Actor)->pos.x.fixed - near_x);
    if (dx > TO_COORD(6) || (dy = abs(SELF(Actor)->pos.y.fixed - near_y)) > TO_COORD(6)) {
        g_GameState->u.field.counter.unsigned_value = 5;
    } else if (dx > TO_COORD(2) || dy > TO_COORD(2)) {
        g_GameState->u.field.counter.unsigned_value = g_Game.members[SELF(Actor)->unk_06].u.field.counter.unsigned_value + 1;
    } else {
        g_GameState->u.field.counter.unsigned_value = g_Game.members[SELF(Actor)->unk_06].u.field.counter.unsigned_value;
    }
    state = g_GameState;
    count = state->u.field.counter.unsigned_value;
    if (count >= 3) {
        if (count >= 6) {
            count = 5;
        }
    } else {
        count = 3;
    }
    state->u.field.counter.unsigned_value = count;
    func_801BD290(near_x, near_y, (s8*)&SELF(Actor)->direction);
    result = func_801BC4D0();
    if ((result & BYTE_MASK) != 1) {
        dy = abs(g_ScratchPad.cells.words[2] - near_x) + abs(g_ScratchPad.cells.words[3] - near_y);
        dx = abs(SELF(Actor)->pos.x.fixed - near_x) + abs(SELF(Actor)->pos.y.fixed - near_y);
        if (dx < dy) {
            SELF(Actor)->direction = dir;
            result                 = 1;
        }
        if ((result & BYTE_MASK) != 1) {
            return result;
        }
    }
    if (!((g_GameFlags | g_AreaWalkFlags) & 1)) {
        if (SELF(Actor)->header.flags & ACTOR_FLAG_OFFSCREEN) {
            saved       = g_GameState;
            g_GameState = g_Game.members;
            cell_x      = (g_Game.members[0].pos.x.fixed + g_Game.members[0].unk_0C * g_Game.members[0].unk_09) & ~0x7FFF;
            cell_y      = (g_Game.members[0].pos.y.fixed + g_Game.members[0].unk_10 * g_Game.members[0].unk_09) & ~0x7FFF;
            if (!(Game_TestPlacement(cell_x, cell_y, SELF(Actor)->voice_flags.scene_flag, Area_HeightRead(cell_x, cell_y)) & BYTE_MASK)) {
                g_GameState              = saved;
                SELF(Actor)->pos.x.fixed = cell_x;
                SELF(Actor)->pos.y.fixed = cell_y;
                SELF(Actor)->header.flags |= ACTOR_FLAG_HIDDEN;
                g_GameState->status.field.flags.unsigned_value &= 0xFE;
                g_GameState->status.field.flags.unsigned_value |= g_Game.members[0].status.field.flags.unsigned_value & 1;
                COORD_INT(SELF(Actor)->pos.z) = Area_HeightRead(cell_x, cell_y);
                SELF(Actor)->draw_layer       = g_Game.members[0].unk_29;
                SELF(Actor)->header.mode      = 2;
                SELF(Actor)->header.step      = 2;
                return 0xFF;
            }
            g_GameState = saved;
        }
    }
    return result;
}
