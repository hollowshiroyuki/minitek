/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/item.h"

bool resource_item_interact_tile(item_t *self, tile_t t, sfVector2i p,
                                    entity_t *player)
{
    resource_t *res = self->res.resource;
    bool interact = (*res->interact)(res, t, p, player);

    if (interact) {
        self->res.count--;
        return (true);
    }
    return (false);
}