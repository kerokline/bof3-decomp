#include "area042_13.h"

MATCH void func_801F2C84(void) {
    Coord x = {SELF(Actor)->vx};
    Coord y = {SELF(Actor)->vy};
    s16   height;
    s32   value;

    height                        = Area_HeightSample(x.fixed, y.fixed);
    value                         = (height << 0x10) + TO_COORD(0x100);
    SELF(Actor)->vz               = value;
    SELF(Actor)->gravity          = value;
    COORD_INT(SELF(Actor)->pos.z) = height;
    SELF(Actor)->voice_flags.raw  = 0;
    if (SYS_TestFlag(g_SceneEventFlags, 0xB) == 0) {
        SELF(Actor)->header.mode = 1;
    } else {
        SELF(Actor)->header.mode = 2;
    }
}
