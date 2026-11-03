/* Clears the five bytes of the bmagic effect work array D_801F17B4. One
 * definition shared by the bmagic overlays; every change here must verify
 * every member. */
/* func_801F006C (magic070), func_801F006C (magic071), func_801F006C (magic072) */
MATCH void func_801F006C(void) {
    D_801F17B4[0] = 0;
    D_801F17B4[1] = 0;
    D_801F17B4[2] = 0;
    D_801F17B4[3] = 0;
    D_801F17B4[4] = 0;
}
