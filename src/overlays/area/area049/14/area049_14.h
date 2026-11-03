#ifndef OVERLAY_WORLD01_AREA049_14_H
#define OVERLAY_WORLD01_AREA049_14_H

/* The world01/area049/14 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world01.h"

void Area_SetCellCode(s16 column, s16 row, u8 code);

#define g_SceneFlags ((void*)g_SceneFlags)

extern u8  D_801F398C[];
extern u16 D_801F5CD4[];
extern u16 D_801F5CD8[];

#endif
