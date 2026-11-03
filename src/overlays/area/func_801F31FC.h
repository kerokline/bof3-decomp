/* One definition shared by the ten world04 area request overlays
 * (emi/world04/area176/13 through emi/world04/area185/13) at 0x801F31FC;
 * every change here must verify every member address. */
MATCH void func_801F31FC(void) {
    switch (D_801490C7) {
        case 0:
            g_MessageRequest = 0xFA;
            break;
        case 1:
            g_MessageRequest = 0xFB;
            break;
        case 2:
            g_MessageRequest = 0xFC;
            break;
        case 3:
            g_MessageRequest = 0xFD;
            break;
        case 4:
            g_MessageRequest = 0xF9;
            break;
    }
}
