#ifndef OVERLAY_WORLD02_AREA098_13_H
#define OVERLAY_WORLD02_AREA098_13_H

/* The world02/area098/13 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world02.h"
#include "work/area_spad.h"

/* The work-window byte offset and row stride this overlay scans. */
#define SCRATCH_ROW_OFFSET    0x00
#define SCRATCH_ROW_STRIDE    0x1C

/* The work-window byte offset, row stride and row count this overlay clears. */
#define SCRATCH_COLUMN_OFFSET 0
#define SCRATCH_COLUMN_STRIDE 0x18
#define SCRATCH_COLUMN_COUNT  8

/* The spin-effect work record the overlay's sprite pass draws. */
typedef struct WorldSpin {
    /* 0x00 */ s32     origin_x; /* the camera x, copied from the scratch record */
    /* 0x04 */ s32     origin_y; /* the camera y */
    /* 0x08 */ s32     origin_z; /* the camera z */
    u8                 unk_0C[4];
    /* 0x10 */ SVECTOR vertex_a;   /* the first rotated vertex offset */
    /* 0x18 */ SVECTOR vertex_b;   /* the second rotated vertex offset */
    /* 0x20 */ s16     angle_lo;   /* the angle accumulator's low half */
    /* 0x22 */ s16     angle_hi;   /* the angle accumulator's high half */
    /* 0x24 */ s16     spin_angle; /* the spin angle */
    s16                unk_26;
    /* 0x28 */ s16     scale; /* the vertex scale */
    /* 0x2A */ s16     fade;  /* the triangle fade */
} WorldSpin;

ASSERT_SIZE(WorldSpin, 0x2C);
ASSERT_OFFSET(WorldSpin, origin_x, 0x00);
ASSERT_OFFSET(WorldSpin, vertex_a, 0x10);
ASSERT_OFFSET(WorldSpin, vertex_b, 0x18);
ASSERT_OFFSET(WorldSpin, spin_angle, 0x24);
ASSERT_OFFSET(WorldSpin, scale, 0x28);
ASSERT_OFFSET(WorldSpin, fade, 0x2A);

extern Callback D_801F5F68[];
extern Callback D_801F5F7C[];
extern Callback D_801F5F88[];
extern Callback D_801F5FAC[];
extern u8       D_801F6510;
extern u8       D_801F6514;

void        Area_ProjectPoint(s32* pos, long* screen_xy);
extern void func_801F526C(void);
extern void func_801F5308(void);
extern void func_801F5940(void);
void        func_801F4D44(void);
void        Area_SetCellCode(s16 column, s16 row, u8 code);

#endif
