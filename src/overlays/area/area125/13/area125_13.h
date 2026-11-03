#ifndef OVERLAY_WORLD03_AREA125_13_H
#define OVERLAY_WORLD03_AREA125_13_H

/* The world03/area125/13 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world03.h"
#include "work/area_spad.h"

/* The work-window byte offset and row stride this overlay scans. */
#define SCRATCH_ROW_OFFSET   0x00
#define SCRATCH_ROW_STRIDE   0x28

/* The row count this overlay clears. */
#define SCRATCH_COLUMN_COUNT 16

extern u8 D_801F364C[];

/* func_801F3384 */
void Area_ClearWorkColumn(void);
s32  func_801F33B0(void);
void func_801F3504(void);
void func_801F31B0(s32 arg0);

#endif
