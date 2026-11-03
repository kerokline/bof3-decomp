#ifndef AREA_COUNTER_H
#define AREA_COUNTER_H

#include "types.h"

/* The counter-step macro shared by the area overlays: write the active mode
 * byte, then step a u16 counter by 0x14. */

/* Counter-step operation: writes a fixed mode byte then steps a u16 counter.
 * Byte-identical across area008/area026.
 *
 * The function stays defined in its target file; this owns the repeated
 * operation (read into a caller-named u16 local, mark active, step by op 0x14).
 * The local keeps the u16 truncation explicit.
 *
 * Usage:
 *   u16 count_;
 *   COUNTER_STEP(counter_extern, flag_extern, count_, +)
 */
#define COUNTER_STEP(counter, flag, count, op) \
    {                                          \
        (count)   = (counter);                 \
        (flag)    = 2;                         \
        (counter) = (u16)((count)op 0x14);     \
    }

#endif
