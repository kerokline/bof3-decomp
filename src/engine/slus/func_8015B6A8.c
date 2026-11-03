#include "engine/slus/slus.h"

/* returns 1 when the first byte of the record at cursor equals D_80146874.
 */
MATCH s32 func_8015B6A8(u8** cursor) {
    u8 result; /* the record byte, then the verdict */

    result = **cursor;
    /* FAKE: retail reads D_80146874 as RecordKey. */
    if ((*(RecordKey*)&D_80146874).ubyte != result) {
        result = 0;
        return result;
    }
    result = 1;
    return result;
}
