/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "gui.h"
#include "menus/menu.h"
#include "entities/entity.h"
#include "screen.h"
#include "hsy.h"

void inventory_menu_draw(menu_t *self, screen_t *screen)
{
    sfVector2i pos1 = (sfVector2i){1, 1};
    sfVector2i pos2 = (sfVector2i){14, 16};
    int val[5] = {pos1.x, pos1.y, pos2.x, pos2.y, self->inv.selection};
    item_t *items = self->inv.player->mob.pla.inventory->items;

    gui_frame_draw(screen, "Inventory", pos1, pos2);
    (*self->funcs.draw_item_list)(self, screen, val, items);
}