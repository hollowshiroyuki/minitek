/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "universe.h"
#include "menus/menu.h"
#include "resources/item.h"

static void input(menu_t *self, int len)
{
    if (self->input->up.clicked)
        self->inv.selection--;
    if (self->input->down.clicked)
        self->inv.selection++;
    self->inv.selection = (len == 0) ? 0 : self->inv.selection;
    self->inv.selection += (self->inv.selection < 0) ? len : 0;
    self->inv.selection -= (self->inv.selection >= len) ? len : 0;
}

void inventory_menu_tick(menu_t *self)
{
    int len = item_list_size(self->inv.player->mob.pla.inventory->items);
    inventory_t *player_inv = self->inv.player->mob.pla.inventory;
    item_t *item;

    input(self, len);
    if (self->input->menu.clicked) {
        universe_set_menu(self->universe, NULL);
        (self->funcs.destroy)(self);
        return;
    }
    if (self->input->attack.clicked && len > 0) {
        item = inventory_remove_item(player_inv, self->inv.selection);
        self->inv.player->mob.pla.active_item = item;
        universe_set_menu(self->universe, NULL);
        (self->funcs.destroy)(self);
    }
}