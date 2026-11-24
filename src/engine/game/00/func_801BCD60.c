#include "game_00.h"

#ifdef NON_MATCHING
NON_MATCHING void func_801BCD60(s32 target_x, s32 target_y) {
    s8  direction;
    s32 start_x;
    s32 start_y;
    s32 diff;
    s32 far;
    s32 far_y;
    s32 tries;
    s32 left;
    s32 side;
    s32 i;
    s32 tried;
    s32 plus;
    s32 minus;
    s16 here;
    s16 height;
    s32 drop;

    if (!(TASK(Actor)->header.flags & 0x80)) {
        return;
    }
    if ((g_GameFlags | g_AreaWalkFlags) & 1) {
        return;
    }
    if (g_Game.members[0].status.field.flags.value & 1) {
        return;
    }
    start_x = TASK(Actor)->pos.x.fixed;
    start_y = TASK(Actor)->pos.y.fixed;
    diff    = start_x - target_x;
    far     = diff;
    if (diff < 0) {
        far = -far;
    }
    diff  = start_y - target_y;
    far_y = diff;
    if (diff < 0) {
        far_y = -far_y;
    }
    if (far < far_y) {
        far = far_y;
    }
    if (far > 0xFFFFF) {
        tries = ((far - 0xF0000) >> 16) + 1;
    } else {
        tries = 1;
    }
    here = Area_HeightRead(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed);
    drop = here - Area_HeightRead(target_x, target_y);
    if (drop < 0) {
        drop = -drop;
    }
    tries -= drop >> 8;
    if (tries <= 0) {
        tries = 1;
    }
    left = tries;
    if (left > 0) {
        side = 0;
    retry:
        func_801BD290(target_x, target_y, &direction);
        TASK(Actor)->pos.x.fixed = start_x + g_FacingSteps[(u8)direction].x * 2 * left;
        TASK(Actor)->pos.y.fixed = start_y + g_FacingSteps[(u8)direction].y * 2 * left;
        height                   = Area_HeightReadStep(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, (u8)direction);
        if (!(Game_TestPlacement(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, TASK(Actor)->voice_flags.scene_flag, height) & BYTE_MASK)) {
            goto found;
        }
        i     = 1;
        tried = TASK(Actor)->pos.x.fixed;
        if (i < side - 1) {
            minus = tried - 0x10000;
            plus  = tried + 0x10000;
            do {
                TASK(Actor)->pos.x.fixed = plus;
                height                   = Area_HeightRead(plus, TASK(Actor)->pos.y.fixed);
                if (!(Game_TestPlacement(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, TASK(Actor)->voice_flags.scene_flag, height) & BYTE_MASK)) {
                    break;
                }
                TASK(Actor)->pos.x.fixed = minus;
                height                   = Area_HeightRead(minus, TASK(Actor)->pos.y.fixed);
                if (!(Game_TestPlacement(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, TASK(Actor)->voice_flags.scene_flag, height) & BYTE_MASK)) {
                    break;
                }
                minus -= 0x10000;
                plus += 0x10000;
                i++;
            } while (i < side - 1);
            if (i < side - 1) {
                goto found;
            }
            i = 1;
        }
        TASK(Actor)->pos.x.fixed = tried;
        tried                    = TASK(Actor)->pos.y.fixed;
        if (i < side - 1) {
            minus = tried - 0x10000;
            plus  = tried + 0x10000;
            do {
                TASK(Actor)->pos.y.fixed = plus;
                height                   = Area_HeightRead(TASK(Actor)->pos.x.fixed, plus);
                if (!(Game_TestPlacement(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, TASK(Actor)->voice_flags.scene_flag, height) & BYTE_MASK)) {
                    break;
                }
                TASK(Actor)->pos.y.fixed = minus;
                height                   = Area_HeightRead(TASK(Actor)->pos.x.fixed, minus);
                if (!(Game_TestPlacement(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed, TASK(Actor)->voice_flags.scene_flag, height) & BYTE_MASK)) {
                    break;
                }
                minus -= 0x10000;
                plus += 0x10000;
                i++;
            } while (i < side - 1);
            if (i < side - 1) {
                goto found;
            }
        }
        left--;
        side++;
        if (left > 0) {
            goto retry;
        }
    }
found:
    if (left != 0) {
        diff = TASK(Actor)->pos.x.fixed - g_Game.members[0].pos.x.fixed;
        if (diff < 0) {
            diff = -diff;
        }
        if (diff > 0x60000 || (diff = TASK(Actor)->pos.y.fixed - g_Game.members[0].pos.y.fixed, ABS(diff) > 0x60000)) {
            if (Area_GetWidth(TASK(Actor)->pos.x.part.integer, TASK(Actor)->pos.y.part.integer) & BYTE_MASK) {
                g_GameState->status.field.flags.unsigned_value &= 0xFE;
                TASK(Actor)->draw_layer = g_AreaDrawMode;
                TASK(Actor)->direction  = direction;
            } else {
                TASK(Actor)->pos.x.fixed = start_x;
                TASK(Actor)->pos.y.fixed = start_y;
            }
        } else {
            TASK(Actor)->pos.x.fixed = start_x;
            TASK(Actor)->pos.y.fixed = start_y;
        }
    } else {
        TASK(Actor)->pos.x.fixed = start_x;
        TASK(Actor)->pos.y.fixed = start_y;
    }
    TASK(Actor)->pos.x.fixed &= ~0x7FFF;
    TASK(Actor)->pos.y.fixed &= ~0x7FFF;
    COORD_INT(TASK(Actor)->pos.z) = Area_HeightRead(TASK(Actor)->pos.x.fixed, TASK(Actor)->pos.y.fixed);
}
#else
INCLUDE_ASM(func_801BCD60);
#endif
