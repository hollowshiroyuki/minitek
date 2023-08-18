/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "screen.h"

void furniture_item_draw_icon(item_t *self, screen_t *screen, sfVector2i pos)
{
    int tex = (self->funcs.get_tex)(self);

    screen_render_item(screen, pos, tex, 0);
}