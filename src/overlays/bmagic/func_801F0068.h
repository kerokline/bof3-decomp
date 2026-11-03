/* Clears the five bytes of the bmagic effect work array D_801F17B0. One
 * definition shared by the bmagic overlays; every change here must verify
 * every member. */
/* func_801F0068 (magic162), func_801F0068 (magic168) */
MATCH void func_801F0068(void) {
    D_801F17B0[0] = 0;
    D_801F17B0[1] = 0;
    D_801F17B0[2] = 0;
    D_801F17B0[3] = 0;
    D_801F17B0[4] = 0;
}
