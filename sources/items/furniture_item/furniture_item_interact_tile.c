/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"
#include "entities/entity.h"

bool furniture_item_interact_tile(item_t *self, tile_t t, sfVector2i p,
                                    entity_t *player)
{
    if ((*t.may_pass)(t, player->floor, p, self->fur.furniture)) {
        self->fur.furniture->pos.x = p.x * 16 + 8;
        self->fur.furniture->pos.y = p.y * 16 + 8;
        floor_add(player->floor, self->fur.furniture);
        self->fur.placed = true;
        return (true);
    }
    return (false);
}