#ifndef MENU_DRAW_H
#define MENU_DRAW_H

#include "types.h"

/* Shared calls made by the start and shop character-sheet renderers. */
extern s32  func_801644D8(s32 arg0, s32 x, s32 y, s32 width, s32 height, s32 shade);
/* emi/etc/game/00: draws one 8x8 sprite, using the low bytes of texture_index and shade_mode. */
extern void func_801AEA80(s32 sprite_x, s32 sprite_y, s32 texture_index, s32 shade_mode);
/* emi/etc/game/00: counts commands over the first twelve encoded bytes. */
extern s32  func_801AF20C(u8* command_stream);

#endif
