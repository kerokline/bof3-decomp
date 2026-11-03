/* One definition shared by the area overlays; every change here must verify every member. */
/* func_801F2C38 */
MATCH void Fish_LocationMessage(void) {
    if (D_80143F04 == 0x3C) {
        g_GameFlags &= 0xDFFF;
    }
}
