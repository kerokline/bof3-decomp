/* One route step for a field character: turn the facing when the route index
 * is even, probe the step ahead, then play the walk or the blocked animation
 * and bump the task state. Char_ProbeFacingCell is the image-local probe; the
 * route table and the animation player are the resident executable's. One
 * definition shared by the plchar character overlays; every change here must
 * verify every member image. */
/* func_801CE898 (plp478), func_801CEC78 (plp578), func_801CEE74 (plp278), func_801CEE74 (plp27a), func_801CEE94 (plp457), func_801CF090 (plp247), func_801CF470 (plp257), func_801CF724 (plp678), func_801CF940 (plp467), func_801CFD20 (plp567), func_801CFF1C (plp267) */
MATCH void Char_WalkStep(void) {
    s16 dist;
    s32 x;
    s32 y;

    if ((g_SpadWork->direction_08 & 1) == 0) {
        g_SpadWork->direction_08 = (g_SpadWork->direction_08 - 1) & 7;
        if ((u8)Char_ProbeFacingCell() == 0) {
            g_SpadWork->direction_08 = (g_SpadWork->direction_08 + 2) & 7;
            if ((u8)Char_ProbeFacingCell() == 0) {
                g_SpadWork->direction_08 = (g_SpadWork->direction_08 - 2) & 7;
            }
        }
    }
    x    = g_SpadWork->x.fixed + g_FacingSteps[g_SpadWork->direction_08].x;
    y    = g_SpadWork->y.fixed + D_80181B98[g_SpadWork->direction_08 * 2];
    dist = Area_ReadHeight(x, y) - g_SpadWork->z.part.integer;
    Area_ReadStepHeight(x, y, g_SpadWork->direction_08);
    if (SP_REF(u8, 0x0u) != 0 && dist >= 65) {
        Actor_RequestScript((g_SpadWork->direction_08 - 1) / 2 + 0x46);
        g_SpadWork->state_02++;
    } else {
        g_SpadWork->unk_2B = 1;
        x                  = g_SpadWork->x.fixed + g_FacingSteps[3].x;
        y                  = g_SpadWork->y.fixed + g_FacingSteps[3].y;
        dist               = Area_ReadStepHeight(x, y, 3);
        if (SP_REF(u8, 0x0u) != 0 && dist >= 65 && g_SpadWork->z.part.integer < Area_ReadHeight(x, y)) {
            g_SpadWork->unk_2B = 0;
        }
        x    = g_SpadWork->x.fixed + g_FacingSteps[5].x;
        y    = g_SpadWork->y.fixed + g_FacingSteps[5].y;
        dist = Area_ReadStepHeight(x, y, 5);
        if (SP_REF(u8, 0x0u) != 0 && dist >= 65 && g_SpadWork->z.part.integer < Area_ReadHeight(x, y)) {
            g_SpadWork->unk_2B = 0;
        }
        /* FAKE: retail reads SND_PlayCue as void(s32). */
        ((void (*)(s32))SND_PlayCue)(g_SpadWork->unk_2C + 0x100);
        Actor_RequestScript((g_SpadWork->direction_08 - 1) / 2 + 0x42);
        g_SpadWork->unk_0A = 5;
    }
    g_SpadWork->unk_0B = 0;
    g_SpadWork->state_02++;
}
