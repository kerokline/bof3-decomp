#include "game_00.h"

#ifdef NON_MATCHING
NON_MATCHING s32 func_801BA678(void) {
    s32 near_x;
    s32 near_y;
    s32 ahead_x;
    s32 ahead_y;
    s32 dx;
    s32 dy;
    u8  facing;
    u8  dir;
    u8  cell;
    u8  kind;
    s16 probe;

    if (g_GameFlags & 0x400) {
        return 1;
    }
    facing = SELF(Actor)->direction;
    if (COORD_FRAC(SELF(Actor)->pos.x) == 0 && COORD_FRAC(SELF(Actor)->pos.y) == 0) {
        return 1;
    }
    switch (D_80181B00[SELF(Actor)->direction][0]) {
        case 1:
            dx = 2;
            break;
        default:
            dx = D_80181B00[SELF(Actor)->direction][0];
            break;
    }
    switch (D_80181B00[SELF(Actor)->direction][1]) {
        case 1:
            dy = 2;
            break;
        default:
            dy = D_80181B00[SELF(Actor)->direction][1];
            break;
    }
    ahead_y = (u16)COORD_INT(SELF(Actor)->pos.y) + dy;
    ahead_x = (u16)COORD_INT(SELF(Actor)->pos.x) + dx;
    near_x  = COORD_INT(SELF(Actor)->pos.x);
    if (D_80181B00[SELF(Actor)->direction][0] == 1) {
        near_x++;
    }
    if (D_80181B00[SELF(Actor)->direction][1] == 1) {
        near_y = COORD_INT(SELF(Actor)->pos.y) + 1;
    } else {
        near_y = COORD_INT(SELF(Actor)->pos.y);
    }
    func_801BBCCC(ahead_x, ahead_y, near_x, near_y);

    dir = SELF(Actor)->direction;
    if (!(dir & 1)) {
        if (COORD_FRAC(SELF(Actor)->pos.x) != 0) {
            if (COORD_FRAC(SELF(Actor)->pos.y) != 0) {
                g_ScratchPad.cells.bytes[8]  = func_801BA278(1, 2, 3, 4, 5);
                g_ScratchPad.cells.bytes[9]  = func_801BA278(4, 5, 0, 0, 0);
                cell                         = func_801BA278(2, 3, 0, 0, 0);
                g_ScratchPad.cells.bytes[10] = cell;
                if (g_ScratchPad.cells.bytes[8] == 0xB0) {
                    return 6;
                }
                if (g_ScratchPad.cells.bytes[9] == 0x70) {
                    Actor_SnapFacing(4, 6, 5);
                    return 7;
                }
                if (cell == 0x70) {
                    Actor_SnapFacing(2, 4, 3);
                    return 7;
                }
                if (func_801BB1B8() & BYTE_MASK) {
                    return 0;
                }
                if ((g_ScratchPad.cells.bytes[9] & 0xF0) == 0xA0 && (SELF(Actor)->direction == FACING_UP || SELF(Actor)->direction == FACING_DOWN)) {
                    return (u8)func_801BB7B0(9);
                }
                if ((g_ScratchPad.cells.bytes[10] & 0xF0) == 0xA0 && (SELF(Actor)->direction == FACING_RIGHT || SELF(Actor)->direction == FACING_LEFT)) {
                    return (u8)func_801BB7B0(10);
                }
                if ((g_ScratchPad.cells.bytes[9] & 0xF0) == 0xA0) {
                    SELF(Actor)->direction = facing;
                    Actor_SnapFacing(4, 6, 5);
                    return (u8)func_801BB7B0(9);
                }
                if ((g_ScratchPad.cells.bytes[10] & 0xF0) == 0xA0) {
                    SELF(Actor)->direction = facing;
                    Actor_SnapFacing(2, 4, 3);
                    return (u8)func_801BB7B0(10);
                }
                Area_WalkTurnFromHighStep(ahead_x, ahead_y);
                return 3;
            }
            cell = g_ScratchPad.cells.bytes[8] = func_801BA278(3, 2, 6, 0, 0);
            if (cell == 0xB0) {
                return 6;
            }
            if (cell == 0x10 || cell == 0x20) {
                Actor_SnapFacing(4, 6, 5);
            }
            if ((g_ScratchPad.cells.bytes[8] & 0xF0) == 0xA0) {
                if (!(SELF(Actor)->direction & 1)) {
                    Actor_SnapFacing(2, 4, 3);
                }
                return (u8)func_801BB7B0(8);
            }
            if (SELF(Actor)->direction & 1) {
                return 3;
            }
            probe = ahead_x;
            if (Area_IsStepTooHigh(probe, probe, COORD_INT(SELF(Actor)->pos.y), COORD_INT(SELF(Actor)->pos.y) + 1, 1) & BYTE_MASK) {
                Actor_SnapFacing(4, 6, 5);
            }
            if (SELF(Actor)->direction & 1) {
                return 3;
            }
            if (Area_IsStepTooHigh(probe, probe, COORD_INT(SELF(Actor)->pos.y), COORD_INT(SELF(Actor)->pos.y) - 1, 1) & BYTE_MASK) {
                Actor_SnapFacing(4, 6, 5);
            }
            return 3;
        }
        cell = g_ScratchPad.cells.bytes[8] = func_801BA278(5, 4, 7, 0, 0);
        if (cell == 0xB0) {
            return 6;
        }
        if (cell == 0x10 || cell == 0x20) {
            Actor_SnapFacing(2, 4, 3);
        }
        if ((g_ScratchPad.cells.bytes[8] & 0xF0) == 0xA0) {
            if (!(SELF(Actor)->direction & 1)) {
                Actor_SnapFacing(4, 6, 5);
            }
            return (u8)func_801BB7B0(8);
        }
        if (SELF(Actor)->direction & 1) {
            return 3;
        }
        probe = ahead_y;
        if (Area_IsStepTooHigh(COORD_INT(SELF(Actor)->pos.x), COORD_INT(SELF(Actor)->pos.x) + 1, probe, probe, 3) & BYTE_MASK) {
            Actor_SnapFacing(2, 4, 3);
        }
        if (SELF(Actor)->direction & 1) {
            return 3;
        }
        if (Area_IsStepTooHigh(COORD_INT(SELF(Actor)->pos.x), COORD_INT(SELF(Actor)->pos.x) - 1, probe, probe, 3) & BYTE_MASK) {
            Actor_SnapFacing(2, 4, 3);
        }
        return 3;
    }

    if (COORD_FRAC(SELF(Actor)->pos.x) != 0) {
        if (COORD_FRAC(SELF(Actor)->pos.y) != 0) {
            if (dir & 2) {
                g_ScratchPad.cells.bytes[8] = func_801BA278(2, 3, 0, 0, 0);
            } else {
                g_ScratchPad.cells.bytes[8] = func_801BA278(4, 5, 0, 0, 0);
            }
            kind = g_ScratchPad.cells.bytes[8];
            if (kind == 0xB0) {
                return 6;
            }
            if (kind == 0x70) {
                return 7;
            }
            if (kind == 0x10 || kind == 0x20) {
                return 0;
            }
            if ((kind & 0xF0) == 0xA0) {
                return (u8)func_801BB7B0(8);
            }
            if (SELF(Actor)->direction & 2) {
                probe = ahead_x;
                if (Area_IsStepTooHigh(probe, probe, COORD_INT(SELF(Actor)->pos.y), COORD_INT(SELF(Actor)->pos.y) + 1, 1) & BYTE_MASK) {
                    return 0;
                }
            } else {
                probe = ahead_y;
                if (Area_IsStepTooHigh(COORD_INT(SELF(Actor)->pos.x), COORD_INT(SELF(Actor)->pos.x) + 1, probe, probe, 3) & BYTE_MASK) {
                    return 0;
                }
            }
        } else if (dir & 2) {
            g_ScratchPad.cells.bytes[8]  = func_801BA278(3, 2, 6, 0, 0);
            g_ScratchPad.cells.bytes[9]  = func_801B9F08(3, 0, 0);
            g_ScratchPad.cells.bytes[10] = func_801B9F08(6, 0, 0);
            g_ScratchPad.cells.bytes[11] = func_801B9F08(2, 0, 0);
            cell                         = g_ScratchPad.cells.bytes[8];
            if (cell == 0xB0) {
                return 6;
            }
            if (cell == 0x70) {
                return 7;
            }
            if (cell == 0x20 || cell == 0x10) {
                if (cell == 0x20 && (g_ScratchPad.cells.bytes[2] & 0xF0) == 0x20) {
                    return 0;
                }
                if (g_ScratchPad.cells.bytes[11] == 0x10) {
                    return 0;
                }
                if (func_801BB934(9, 10, 1, 0x10) & BYTE_MASK) {
                    return 0;
                }
                if (g_ScratchPad.cells.bytes[11] == 0xA2) {
                    if (func_801BB934(9, 10, 5, 0xA2) & BYTE_MASK) {
                        return 0;
                    }
                } else if (func_801BB934(9, 10, 1, 0xA2) & BYTE_MASK) {
                    return 0;
                }
            }
            if ((g_ScratchPad.cells.bytes[8] & 0xF0) == 0xA0) {
                return (u8)func_801BB7B0(8);
            }
            probe = ahead_x;
            if (Area_IsStepTooHigh(probe, probe, COORD_INT(SELF(Actor)->pos.y), COORD_INT(SELF(Actor)->pos.y) + 1, 1) & BYTE_MASK) {
                SELF(Actor)->direction = FACING_UP;
                return 1;
            }
            if (Area_IsStepTooHigh(probe, probe, COORD_INT(SELF(Actor)->pos.y), COORD_INT(SELF(Actor)->pos.y) - 1, 1) & BYTE_MASK) {
                SELF(Actor)->direction = FACING_DOWN;
                return 1;
            }
        }
    } else if (!(dir & 2)) {
        g_ScratchPad.cells.bytes[8]  = func_801BA278(5, 4, 7, 0, 0);
        g_ScratchPad.cells.bytes[9]  = func_801B9F08(5, 0, 0);
        g_ScratchPad.cells.bytes[10] = func_801B9F08(7, 0, 0);
        g_ScratchPad.cells.bytes[11] = func_801B9F08(4, 0, 0);
        cell                         = g_ScratchPad.cells.bytes[8];
        if (cell == 0xB0) {
            return 6;
        }
        if (cell == 0x70) {
            return 7;
        }
        if (cell == 0x20 || cell == 0x10) {
            if (cell == 0x20 && (g_ScratchPad.cells.bytes[4] & 0xF0) == 0x20) {
                return 0;
            }
            if (g_ScratchPad.cells.bytes[11] == 0x10) {
                return 0;
            }
            if (func_801BB934(9, 10, 7, 0x10) & BYTE_MASK) {
                return 0;
            }
            if (g_ScratchPad.cells.bytes[11] == 0xA2) {
                if (func_801BB934(9, 10, 3, 0xA2) & BYTE_MASK) {
                    return 0;
                }
            } else if (func_801BB934(9, 10, 7, 0xA2) & BYTE_MASK) {
                return 0;
            }
        }
        if ((g_ScratchPad.cells.bytes[8] & 0xF0) == 0xA0) {
            return (u8)func_801BB7B0(8);
        }
        probe = ahead_y;
        if (Area_IsStepTooHigh(COORD_INT(SELF(Actor)->pos.x), COORD_INT(SELF(Actor)->pos.x) + 1, probe, probe, 3) & BYTE_MASK) {
            SELF(Actor)->direction = FACING_LEFT;
            return 1;
        }
        if (Area_IsStepTooHigh(COORD_INT(SELF(Actor)->pos.x), COORD_INT(SELF(Actor)->pos.x) - 1, probe, probe, 3) & BYTE_MASK) {
            SELF(Actor)->direction = FACING_RIGHT;
            return 1;
        }
    }
    return 3;
}
#else
INCLUDE_ASM(func_801BA678);
#endif
