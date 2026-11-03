#ifndef OVERLAY_BMAGIC_MAGIC041_03_H
#define OVERLAY_BMAGIC_MAGIC041_03_H

/* The bmagic/magic041/03 overlay. Only this image includes the file. */

#include "overlays/bmagic/bmagic.h"

typedef struct BattleHandlerTable6 {
    Callback handlers[6];
} BattleHandlerTable6;

ASSERT_SIZE(BattleHandlerTable6, 0x18);

extern BattleHandlerTable6 D_801EEC04;

#endif
