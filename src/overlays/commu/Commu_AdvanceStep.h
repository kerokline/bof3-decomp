/* Adds one to D_801448EC unless the game is in state 2. One definition
 * shared by the commu overlays; every change here must verify every member. */
/* func_801D5A9C (commu02/08), func_801D7E30 (commu02/08, a second copy in that image), func_801D1670 (commu04/06), func_801D121C (commu03/06) */
MATCH void Commu_AdvanceStep(void) {
    u8* state;

    if (g_GameStateIndex != 2) {
        state = &D_801448EC;
        *state += 1;
    }
}
