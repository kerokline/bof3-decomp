#ifndef OVERLAY_WORLD01_AREA059_13_H
#define OVERLAY_WORLD01_AREA059_13_H

/* The world01/area059/13 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world01.h"

void Area_SetCellCode(s16 column, s16 row, u8 code);

extern u8 D_801F3824[];

/* func_80196718 */
void GFX_FreePaletteFadeTarget(void* target);
void func_801F30A8(s32* pos);

#endif
