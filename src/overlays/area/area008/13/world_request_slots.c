#include "area008_13.h"

/* Request-slot codes; 0xFFFF is the reset sentinel. */
u16         D_801F53F0[2] = {0xFFFF, 0x004F};
volatile u8 D_801F53F4    = 0;
u8          D_801F53F5    = 0;
u8          D_801F53F6    = 0;
u8          D_801F53F7    = 0;
