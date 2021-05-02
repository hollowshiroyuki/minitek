/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/resource.h"
#include "entities/entity.h"

static bool is_in_sources(resource_t *self, tile_t *tile)
{
    for (int i = 0; self->plant.sources[i] && i < 5; i++) {
        if (self->plant.sources[i]->id == tile->id) {
            return (true);
        }
    }
    return (false);
}

bool plant_interact(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla)
{
    bool in_sources = is_in_sources(s, &tile);

    if (in_sources) {
        floor_set_tile(pla->floor, p, *s->plant.target, 0);
        return (true);
    }
    return (false);
}