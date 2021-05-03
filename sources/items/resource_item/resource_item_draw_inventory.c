/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "gui.h"
#include "screen.h"

void resource_item_draw_inventory(item_t *self, screen_t *screen, sfVector2i p)
{
    sfVector2i off_pos = (sfVector2i){p.x + 8, p.y};
    int tex = (self->funcs.get_tex)(self);

    resource_item_draw_icon(self, screen, p);
    gui_text_draw(self->res.resource->name, screen, off_pos, sfWhite);
}