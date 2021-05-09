/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "random.h"
#include <stdio.h>
#include "floor.h"
#include "entities/entity.h"
#include "entities_id.h"

static void tick_tiles(floor_t *self)
{
    sfVector2i pos;
    tile_t tile = {0};

    for (int i = 0; i < self->size.x * self->size.y / 50; i++) {
        pos.x = random_int(self->size.x);
        pos.y = random_int(self->size.y);
        tile = floor_get_tile(self, pos);
        if (tile.tick)
            (*tile.tick)(tile, self, pos);
    }
}

static void tick_entities(floor_t *self, entity_t *entities)
{
    sfVector2i pos;
    sfVector2i npos;
    entity_t *next;

    for (entity_t *e = entities; e; e = next) {
        next = e->next;
        pos = (sfVector2i){e->pos.x >> 4, e->pos.y >> 4};
        (*e->funcs.tick)(e);
        if (e->removed) {
            entities_remove(&self->entities, e);
            floor_remove_entity(self, pos, e);
        } else {
            npos = (sfVector2i){e->pos.x >> 4, e->pos.y >> 4};
            if (npos.x != pos.x || npos.y != pos.y) {
                floor_remove_entity(self, pos, e);
                floor_insert_entity(self, npos, e);
            }
        }
    }
}

void floor_tick(floor_t *self)
{
    floor_try_spawn(self, 5);
    tick_tiles(self);
    tick_entities(self, self->entities);
    self->tickCount++;
}