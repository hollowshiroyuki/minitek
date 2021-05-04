/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "screen.h"
#include "floor.h"
#include <stdio.h>

void draw_active_item(universe_t *self, screen_t *screen)
{
    item_t *active_item = self->player->mob.pla.active_item;
    sfVector2i size = screen->size;
    sfVector2i pos = {size.x  - 12 * 8, size.y - 16};

    if (active_item)
        (active_item->funcs.draw_inventory)(active_item, screen, pos);
}

void universe_draw_gui(universe_t *self, screen_t *screen)
{
    draw_active_item(self, screen);
    if (self->menu)
        (*self->menu->funcs.draw)(self->menu, screen);
}