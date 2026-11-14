#ifndef OVERLAY_BMAGIC_MAGIC082_03_H
#define OVERLAY_BMAGIC_MAGIC082_03_H

/* The bmagic/magic082/03 overlay. Only this image includes the file. */

#include "overlays/bmagic/bmagic.h"

extern BMagicEffectFuncs D_801EEC04;

extern Callback D_801F0D1C[];
void            func_801EF720(void);
void            func_801EFA00(void);

void func_801F03E0(void);

void func_801F0A84(s32 radius);
s32  func_801EF3A0(void);

/* battle/battle/15: the target selector of each effect side, and the test of a selector against the target. */
extern u8 D_800B6BF0[];
u8        func_800AED5C(s32 selector, u32 battler_index);

#endif
