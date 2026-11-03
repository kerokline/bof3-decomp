#ifndef SYS_SCENE_H
#define SYS_SCENE_H

#include "types.h"
#include "psx/psyq.h"

/* The per-frame camera turn step, in the 4096-unit scene rotation. */
#define AREA_CAMERA_STEP 22

/* D_801492D8 */
extern SVECTOR g_AreaCameraAngle; /* x, y, z scene rotation halfwords */

#endif
