/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "resources/item.h"
#include "entities/entity.h"

bool furniture_item_interact_tile(item_t *self, tile_t t, sfVector2i p,
                                    entity_t *player)
{
    bool may_pass = true;

    if (t.may_pass)
        may_pass = (*t.may_pass)(t, player->floor, p, self->fur.furniture);
    if (may_pass) {
        self->fur.furniture->pos.x = p.x * 16 + 8;
        self->fur.furniture->pos.y = p.y * 16 + 8;
        floor_add(player->floor, self->fur.furniture);
        self->fur.placed = true;
        return (true);
    }
    return (false);
}