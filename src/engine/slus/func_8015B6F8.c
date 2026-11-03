#include "engine/slus/slus.h"

/* returns bit 0 of D_80146871, inverted unless the record byte is 1.
 */
MATCH s32 func_8015B6F8(u8** cursor) {
    if (**cursor != 1) {
        return (D_80146871 & 1) ^ 1;
    }
    return D_80146871 & 1;
}
