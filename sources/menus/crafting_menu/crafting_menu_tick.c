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
        self->craft.selection--;
    if (self->input->down.clicked)
        self->craft.selection++;
    self->craft.selection = (len == 0) ? 0 : self->craft.selection;
    self->craft.selection += (self->craft.selection < 0) ? len : 0;
    self->craft.selection -= (self->craft.selection >= len) ? len : 0;
}

static void craft_item(menu_t *self, int len)
{
    recipe_t *r = recipe_list_get(self->craft.recipes, self->craft.selection);
    (*r->funcs.check_can_craft)(r, self->craft.player);
    if (r->can_craft) {
        (r->funcs.deduct_cost)(r, self->craft.player);
        (r->funcs.craft)(r, self->craft.player);
    }
    for (recipe_t *cur = self->craft.recipes; cur; cur = cur->next)
        (*cur->funcs.check_can_craft)(cur, self->craft.player);
    recipe_list_sort(&self->craft.recipes);
}

void crafting_menu_tick(menu_t *self)
{
    int len = recipe_list_size(self->craft.recipes);

    input(self, len);
    if (self->input->menu.clicked) {
        universe_set_menu(self->universe, NULL);
        (self->funcs.destroy)(self);
        return;
    }
    if (self->input->attack.clicked && len > 0) {
        craft_item(self, len);
    }
}