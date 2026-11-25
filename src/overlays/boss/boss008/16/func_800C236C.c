#include "boss008_16.h"

#ifdef NON_MATCHING
static inline u8* KindColor(u8 kind) {
    return &D_800C2640[(kind - 8) * 3];
}

NON_MATCHING void func_800C236C(u8 phase) {
    s32           ring[64][2];
    EnemyBattler* enemy;
    POLY_G3*      prim;
    u8            i;
    u8            next;

    i = 0;
    do {
        ring[i][0] = FIXED_MUL(rsin(i << 7), phase);
        ring[i][1] = FIXED_MUL(rcos(i << 7), phase);
        i++;
    } while (i < 64);

    GFX_ADD_LAYER_DRAW_MODE(3, GetTPage(0, 0, 0x3C0, 0));
    i = 0;
    do {
        prim = (POLY_G3*)g_GfxPrimCursor;
        SetPolyG3(prim);
        setRGB0(prim, 0xFF, 0xFF, 0xFF);
        prim->r1 = KindColor(g_BattleCurrentEnemy->unk_F0)[0];
        prim->g1 = KindColor(g_BattleCurrentEnemy->unk_F0)[1];
        prim->b1 = KindColor(g_BattleCurrentEnemy->unk_F0)[2];
        prim->r2 = KindColor(g_BattleCurrentEnemy->unk_F0)[0];
        prim->g2 = KindColor(g_BattleCurrentEnemy->unk_F0)[1];
        prim->b2 = KindColor(g_BattleCurrentEnemy->unk_F0)[2];
        enemy    = TASK(EnemyBattler);
        next     = (i + 1) & 0x1F;
        setXY3(prim, enemy->screen_x, enemy->screen_y, enemy->screen_x + ring[i][0], enemy->screen_y + ring[i][1], enemy->screen_x + ring[next][0], enemy->screen_y + ring[next][1]);
        SetSemiTrans(prim, 1);
        GFX_AddPrim(3, sizeof(POLY_G3));
        i++;
    } while (i < 64);
}
#else
INCLUDE_ASM(func_800C236C);
#endif
