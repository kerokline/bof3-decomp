#include "boss018_16.h"

MATCH void func_800C2A40(void) {
    switch (D_80145F09[0]) {
        case 0:
            g_BattlePartyOrder = 0x2C;
            break;
        case 1:
            g_BattlePartyOrder = 0x2D;
            break;
        case 5:
            g_BattlePartyOrder = 0x2E;
            break;
        case 6:
            g_BattlePartyOrder = 0x2F;
            break;
    }
}
