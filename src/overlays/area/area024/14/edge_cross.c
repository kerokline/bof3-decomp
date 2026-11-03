#include "area024_14.h"

MATCH s16 func_801F4158(DVECTOR* a, DVECTOR* b, DVECTOR* c) {
    DVECTOR edge1;
    DVECTOR edge2;

    edge1.vx = b->vx - a->vx;
    edge1.vy = b->vy - a->vy;
    edge2.vx = c->vx - b->vx;
    edge2.vy = c->vy - b->vy;
    return edge1.vx * edge2.vy - edge1.vy * edge2.vx;
}
