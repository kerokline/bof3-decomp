#ifndef OVERLAY_WORLD04_AREA168_13_H
#define OVERLAY_WORLD04_AREA168_13_H

/* The world04/area168/13 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world04.h"
#include "work/area_spad.h"

/* The work origin offset, step and threshold this overlay advances. */
#define AREA_ORIGIN_OFFSET       0x30
#define ACTOR_SCREEN_X_STEP      0x10
#define ACTOR_SCREEN_X_THRESHOLD 0x80

/* The scratchpad cell holding this mode's work pointer. */

/* The party position in 16.16 fixed point. */
extern s32 D_80145EC4;
/* The payload's data after the last function; the per-state handler tables
 * start at 0xC. */
extern u8  D_801F4B2C[];

/* The game-overlay state bytes the cancel path resets. */
#endif
