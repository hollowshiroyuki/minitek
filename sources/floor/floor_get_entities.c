/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "floor.h"
#include "entities_id.h"
#include "entities/entity.h"
#include <stdio.h>
#include "consts.h"

static void add_to_result(entity_t **r, int *i, sfVector2i p[2], entity_t *e)
{
    if ((*e->funcs.intersects)(e, p[0], p[1])) {
        r[*i] = e;
        (*i)++;
    }
}

entity_t **floor_get_entities(floor_t *self, sfVector2i pos1, sfVector2i pos2)
{
    sfVector2i pos1t = (sfVector2i){(pos1.x >> 4) - 1, (pos1.y >> 4) - 1};
    sfVector2i pos2t = (sfVector2i){(pos2.x >> 4) + 1, (pos2.y >> 4) + 1};
    sfVector2i poss[2] = {pos1, pos2};
    int ent_count = entities_count(self->entities);
    entity_t **list = malloc((ent_count + 1) * sizeof(entity_t *));
    entity_t **on_tile;
    int ri = 0;

    memset(list, 0, (ent_count + 1) * sizeof(entity_t *));
    for (int y = pos1t.y; y <= pos2t.y; y++) {
        for (int x = pos1t.x; x <= pos2t.x; x++) {
            if (x < 0 || y < 0 || x >= self->size.x || y >= self->size.y)
                continue;
            on_tile = self->entities_in_tiles[x + y * self->size.x];
            for (int i = 0; i < entities_per_tile && on_tile[i]; i++) {
                add_to_result(list, &ri, poss, on_tile[i]);
            }
        }
    }
    return (list);
}