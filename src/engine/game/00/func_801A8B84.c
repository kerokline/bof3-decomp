#include "game_00.h"

MATCH s8 func_801A8B84(s32 handler_x, s32 handler_y) {
    s32 kind;

    kind = LOHU(g_GameAreaId);
    switch (kind) {
        case 0x28:
            return func_801F3400();
        case 0x30:
            return func_801F4C28();
        case 0x6F:
            return func_801F4140();
        case 0x94:
            return func_801F4108();
        case 0xA7:
            return func_801F48B4();
        case 0xA9:
            return func_801F3A28();
        case 0xAB:
            return func_801F3EBC();
        case 0xAD:
            return func_801F4DF8();
        default:
            return 0;
    }
}
