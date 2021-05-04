/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "gui.h"
#include "screen.h"
#include "entities/entity.h"

void furniture_item_draw_inventory(item_t *self, screen_t *scr, sfVector2i p)
{
    sfVector2i off_pos = (sfVector2i){p.x + 8, p.y};
    char *furniture_name = self->fur.furniture->fur.name;
    int tex = (self->funcs.get_tex)(self);

    furniture_item_draw_icon(self, scr, p);
    gui_text_draw(furniture_name, scr, off_pos, sfWhite);
}