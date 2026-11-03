/* Draw the visible stock rows and the panel header. One definition shared by
 * the shop and start overlays; each image header declares the stock count,
 * rows, first row and the two draw helpers.
 */
/* func_801D67B0 (shop), func_801E6C68 (start) */
MATCH void SAVE_DrawSlots(s16 panel_x, s16 panel_y, u8 row_cursor) {
    MenuListRow* row;
    s32          idx;
    s32          x;
    s32          y;
    u8           i;

    i = 0;
    if (g_SaveSlotCount != 0) {
        x = (s16)(panel_x + 0x10);
        do {
            idx = i;
            y   = (s16)(panel_y + 6 + idx * 0x38);
            if (g_SaveSlots[idx].source_index != GAME_NONE) {
                row = &g_SaveSlots[idx];
            } else {
                row = NULL;
            }
            SAVE_DrawSlot(idx, x, y, (void*)row);
            i++;
        } while (i < g_SaveSlotCount);
    }
    Menu_DrawCursorFrame((u16)(panel_x + 0x10), (u16)(panel_y + 6 + g_SaveSlotFirst * 0x38), 0xD1, 0x34, row_cursor, 6);
}
