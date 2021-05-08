/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "universe.h"
#include "menus/menu.h"
#include "menu_funcs.h"
#include "random.h"

void universe_change_floor(universe_t *self, int dir)
{
    int depth = self->active_floor->depth;
    sfVector2i size = self->active_floor->size;

    entities_remove(&self->active_floor->entities, self->player);
    self->active_floor->player = 0;
    depth += dir;
    if (depth > 15)
        depth = 15;
    if (!self->floors[depth]) {
        srand(self->seeds[1]);
        self->floors[depth] = floor_create(size, depth, self->active_floor);
        self->seeds[1] = random_int(INT_MAX);
    }
    self->active_floor = self->floors[depth];
    self->player->next = 0;
    self->player->pos.x = (self->player->pos.x >> 4) * 16 + 8;
    self->player->pos.y = (self->player->pos.y >> 4) * 16 + 8;
    floor_add(self->active_floor, self->player);
}