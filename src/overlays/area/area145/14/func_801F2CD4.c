#include "area145_14.h"

MATCH void func_801F2CD4(void) {
    g_SpadWork->x.fixed = 0x318000;
    g_SpadWork->y.fixed = 0x638000;
    g_SpadWork->gravity = 0x500000;
    g_SpadWork->vz      = 0x500000;
    SND_QueueSelectionFx(0x208);
    g_SpadWork->unk_01++;
    g_SpadWork->state_02 = 0;
}
