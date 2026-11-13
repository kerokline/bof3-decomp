#ifndef OVERLAY_BMAGIC_MAGIC172_03_H
#define OVERLAY_BMAGIC_MAGIC172_03_H

/* The bmagic/magic172/03 overlay. Only this image includes the file. */

#include "overlays/bmagic/bmagic.h"

/* The effect timer drops by 2 per tick. */
#define EFFECT_TIMER_TICK 2

extern Callback D_801F0B90[];

/* The red and blue weight of one ring shade; the green follows the effect timer alone. */
typedef struct Magic172Shade {
    u8 red;
    u8 blue;
} Magic172Shade;

extern Magic172Shade D_801F0B9C[];

void            func_800AF3A0(VECTOR pos, s16 step);
void            func_801EEDD8(void);
void            func_801EF7CC(void);
void            func_801EFA2C(void);
void            func_801EFD04(void);
void            func_801EFFE8(void);
void            func_801F02C8(s32 angle, s32 count);
void            func_801F05E8(s32 angle, s32 count);
extern Callback D_801F0B7C[];
void            func_801F0908(void);

#endif
