#ifndef OVERLAY_WORLD03_AREA130_13_H
#define OVERLAY_WORLD03_AREA130_13_H

/* The world03/area130/13 overlay: one file per split function
 * and its data. Only this image includes the file. */

#include "overlays/area/world03.h"
#include "work/area_spad.h"

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

extern u8  D_80144F5B;
extern u8  D_80144F5C;
extern u8  D_80145FD0;
extern s16 D_80145FFE;
extern s16 D_80146000;
extern u8  D_80146110;
extern s16 D_8014613E;
extern s16 D_80146140;
extern s16 D_801469EA;
extern u8  D_801F3ED8[];

s32  Party_AddVitalItem(u8 item_id);
void Area_ProjectPoint(s32* pos, long* screen_xy);

#endif
