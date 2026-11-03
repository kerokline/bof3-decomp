#include "game_00.h"

#ifdef NON_MATCHING
NON_MATCHING void func_8019B704(void) {
    s32 saved;
    s32 acc;
    s32 total;
    s32 delta;
    s16 dist;
    s16 temp;

    g_SpadWork->unk_06 = 0;
    g_SpadWork->unk_07 = 0;
    if (g_SpadWork->unk_0C != 0) {
        saved              = g_SpadWork->unk_0C;
        acc                = saved + g_SpadWork->unk_18;
        g_SpadWork->unk_0C = acc;
        if (acc < 0) {
            acc = -acc;
        }
        if (acc < ONE) {
            g_SpadWork->unk_0C = saved;
            g_SpadWork->unk_18 = 0;
        }
        total               = g_SpadWork->x.fixed + g_SpadWork->unk_0C;
        g_SpadWork->x.fixed = total;
        delta               = total - D_80145EC4;
    } else {
        saved              = g_SpadWork->unk_10;
        acc                = saved + g_SpadWork->unk_1C;
        g_SpadWork->unk_1C = acc;
        if (acc < 0) {
            acc = -acc;
        }
        if (acc < ONE) {
            g_SpadWork->unk_10 = saved;
            g_SpadWork->unk_1C = 0;
        }
        total               = g_SpadWork->y.fixed + g_SpadWork->unk_10;
        g_SpadWork->y.fixed = total;
        delta               = total - D_80145EC8;
    }
    if (delta < 0) {
        delta = -delta;
    }
    if ((g_SpadWork->unk_18 == 0) && (g_SpadWork->unk_1C == 0)) {
        g_SpadWork->unk_06 = 1;
        g_SpadWork->unk_07 = 0;
    }
    acc                        = g_SpadWork->unk_14 + g_SpadWork->unk_20;
    g_SpadWork->unk_14         = acc;
    g_SpadWork->z.part.integer = (u16)(g_SpadWork->z.part.integer + acc);
    if ((g_AreaCameraMoving == 0) && (delta > 0x40000) && (g_AreaScrollTargetX == D_80145EC4) &&
        (g_AreaScrollTargetY == D_80145EC8)) {
        if (g_SpadWork->unk_0C > 0) {
            D_8014930A = (s16)(D_8014930A + 5);
        } else if (g_SpadWork->unk_0C < 0) {
            D_8014930A = (s16)(D_8014930A - 5);
        } else if (g_SpadWork->unk_10 > 0) {
            D_8014930E = (s16)(D_8014930E + 5);
        } else if (g_SpadWork->unk_10 < 0) {
            D_8014930E = (s16)(D_8014930E - 5);
        }
        temp                   = Area_SampleHeight(g_AreaScrollTargetX, g_AreaScrollTargetY);
        g_AreaCameraHeightStep = 0;
        if (temp < (s16)g_AreaCameraHeight) {
            g_AreaCameraHeightStep = (s16)((temp - (s16)g_AreaCameraHeight) / 20);
        }
        g_AreaCameraStep   = 0x40;
        g_SpadWork->unk_09 = 0x14;
    }
    dist = Area_SampleHeight(g_SpadWork->x.fixed, g_SpadWork->y.fixed);
    if (dist < (s16)g_SpadWork->z.part.integer) {
        g_SpadWork->unk_20 = -8;
    } else {
        g_SpadWork->unk_14         = 0;
        g_SpadWork->unk_20         = 0;
        g_SpadWork->z.part.integer = (u16)dist;
    }
    if ((func_8019C028() & BYTE_MASK) == 0) {
        if ((func_8019C344(g_SpadWork->x.fixed, g_SpadWork->y.fixed) & BYTE_MASK) != 0) {
            g_SpadWork->unk_06 = 1;
            g_SpadWork->unk_07 = 2;
        } else if ((func_8019C1E4() & BYTE_MASK) != 0) {
            g_SpadWork->unk_06 = 1;
            g_SpadWork->unk_07 = 1;
        }
        if (g_SpadWork->unk_06 != 0) {
            switch (g_SpadWork->unk_07) {
                case 0:
                    if ((g_SpadWork->x.part.fraction == 0) && (g_SpadWork->y.part.fraction == 0)) {
                        g_SpadWork->unk_07 = 0;
                        g_SpadWork->unk_0A = 0;
                        Actor_SelectScript(0);
                        g_SpadWork->unk_01 = 5;
                    } else {
                        func_8019C124(0);
                    }
                    break;
                case 1:
                    func_8019C124(0);
                    break;
                default:
                    func_8019C124(1);
                    break;
            }
        }
        func_8014D978();
        Area_SetDrawMode();
    }
}
#else
INCLUDE_ASM(func_8019B704);
#endif
