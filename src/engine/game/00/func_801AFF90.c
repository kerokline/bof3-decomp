#include "game_00.h"

MATCH s16 func_801AFF90(void* origin, void* first_point, void* second_point) {
    s16 y1;
    s16 y2;

    y1 = FIELD(s16, first_point, 0u);
    y2 = FIELD(s16, first_point, 2u);
    return (s16)(((y1 - FIELD(s16, origin, 0u)) * (FIELD(s16, second_point, 2u) - y2)) -
                 ((y2 - FIELD(s16, origin, 2u)) * (FIELD(s16, second_point, 0u) - y1)));
}
