#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

#include "types.h"

/* Small arithmetic, bit and in-place byte-view helpers shared by the game
 * sources. LO/HI read the little-endian halves of an object without copying. */

/* The byte value that means no slot, index or result in a byte field. It is
 * compared, never used as a mask. */
#define GAME_NONE        0xFF

/* Counts and sizes */
#define ARRAY_COUNT(x)   (sizeof(x) / sizeof((x)[0]))
#define OFF(type, field) DECOMP_OFFSETOF(type, field)
#define ALIGN(x, n)      (((x) + ((n) - 1)) & ~((n) - 1))

/* The low byte and low halfword of a value: `x & BYTE_MASK`. A mask, never a sentinel (GAME_NONE). */
#define BYTE_MASK        0xFF
#define HALF_MASK        0xFFFF

/* Bits and arithmetic. BIT is a signed int like the open-coded `1 << n`. */
#define BIT(n)           (1 << (n))
#define MIN(a, b)        (((a) < (b)) ? (a) : (b))
#define MAX(a, b)        (((a) > (b)) ? (a) : (b))
#define CLAMP(x, lo, hi) (((x) < (lo)) ? (lo) : (((x) > (hi)) ? (hi) : (x)))
#ifndef ABS /* PsyQ <abs.h> spells it identically */
#define ABS(x) (((x) >= 0) ? (x) : (-(x)))
#endif
#define SQ(x)             ((x) * (x))

/* A random value below the next power of two: the mask must be 2^n - 1. */
#define RANDOM_MASK(mask) (rand() & (mask))

/* LO/HI name the little-endian half or byte of the object: the expansion is
 * the same cast-and-dereference expression the retail code compiles. The
 * argument stays addressable, so these are lvalues. */
#define LOB(x)            (*(s8*)&(x))
#define LOBU(x)           (*(u8*)&(x))
#define LOH(x)            (*(s16*)&(x))
#define LOHU(x)           (*(u16*)&(x))
#define HIH(x)            (((s16*)&(x))[1])
#define HIHU(x)           (((u16*)&(x))[1])
#define LOW(x)            (*(s32*)&(x))
#define LOWU(x)           (*(u32*)&(x))

#endif
