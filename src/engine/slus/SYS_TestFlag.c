#include "engine/slus/slus.h"

/* returns bit bit_index of the byte array at bits.
 */
/* func_8015B5D4 */
MATCH s32 SYS_TestFlag(void* bits, s32 bit_index) {
    return (((u8*)bits)[((u32)bit_index & BYTE_MASK) >> 3] >> (bit_index & 7)) & 1;
}
