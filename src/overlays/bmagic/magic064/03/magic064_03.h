#ifndef OVERLAY_BMAGIC_MAGIC064_03_H
#define OVERLAY_BMAGIC_MAGIC064_03_H

/* The bmagic/magic064/03 overlay. Only this image includes the file. */

#include "overlays/bmagic/bmagic.h"

/* Signed here: the exe's Area_ProbeCell reads this cell with `lh`; scena00/00 reads the
 * same address with `lhu`, so its unsigned view stays in that image header. */
/* D_80149322 */
extern s16               g_AreaTileOriginY;
extern BattleResultRings D_801EEC40;
extern void*             D_801F28B4;

void GFX_FreePaletteFadeTarget(void* target);
void func_801EF8F4(void);
void func_801F001C(void);
void func_801F04A0(void);
void func_801F05A4(void);

#endif
