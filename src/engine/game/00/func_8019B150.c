#include "game_00.h"

MATCH void func_8019B150(void) {
    Actor* work;
    s32    flag;

    flag = 1;
    Area_FindSceneRecord(g_SpadWork->unk_2C);

    g_SpadWork->unk_48 = (u8)flag;

    g_SpadWork->flags_24 = 0;

    work         = g_SpadWork;
    work->unk_2A = (u8)(work->unk_06 >> 7);

    Actor_SelectScript((u8)(g_SpadWork->unk_06 & 0x7F));
    g_SpadWork->unk_01 = (u8)flag;
}
