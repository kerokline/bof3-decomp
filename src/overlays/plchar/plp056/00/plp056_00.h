#ifndef OVERLAY_PLCHAR_PLP056_00_H
#define OVERLAY_PLCHAR_PLP056_00_H

/* The plchar/plp056/00 overlay's local declarations. Only this image
 * includes the file. */

#include "overlays/plchar/plchar.h"
#include "work/area_spad.h"

/* The tail callback table's entry count in this image. */
#define PLCHAR_STEP_TABLE_COUNT 31

/* The two route directions this character program turns between. */
#define CHARACTER_FACING_AWAY   5
#define CHARACTER_FACING_BACK   3

/* The field work row this overlay moves, at scratchpad 0x1F800044. */

extern Callback D_801D0858[];
extern Callback D_801D0864[];
extern Callback D_801D0870[];
extern Callback D_801D087C[];
extern Callback D_801D0888[];
extern Callback D_801D0894[];
extern Callback D_801D089C[];
extern Callback D_801D08B0[];
extern Callback D_801D08BC[];
extern Callback D_801D08C8[];

#endif
