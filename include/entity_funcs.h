/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ENTITY_FUNCS_H_
#define ENTITY_FUNCS_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "screen.h"
#include "tiles/tile.h"
#include "resources/item.h"

typedef struct entity_s entity_t;

typedef struct entity_funcs_s
{
    void (*draw)(entity_t *self, screen_t *scr);
    void (*tick)(entity_t *self);
    void (*destroy)(entity_t *self);
    bool (*intersects)(entity_t *self, sfVector2i pos1, sfVector2i pos2);
    bool (*blocks)(entity_t *self, entity_t *entity);
    void (*hurt)(entity_t *self, entity_t *entity, int dmg, int dir);
    void (*hurt_tile)(entity_t *self, tile_t tile, sfVector2i pos, int dmg);
    bool (*move)(entity_t *self, sfVector2i pos);
    bool (*move_axis)(entity_t *self, sfVector2i pos);
    void (*touched_by)(entity_t *self, entity_t *entity);
    bool (*is_block_by)(entity_t *self, entity_t *entity);
    void (*touch_item)(entity_t *self, entity_t *item);
    bool (*can_swim)(entity_t *self);
    bool (*interact)(entity_t *self, entity_t *entity, item_t *item, int dir);
    bool (*use)(entity_t *self, entity_t *entity, int dir);
    bool (*start_pos)(entity_t *self, floor_t *floor);
    void (*init)(entity_t *self, floor_t *floor);
    void (*heal)(entity_t *self, int heal);
    void (*die)(entity_t *self);
    void (*do_hurt)(entity_t *entity, int dmg, int dir);
} entity_funcs_t;

void entity_funcs_combine(entity_funcs_t *r,
                            const entity_funcs_t *a,
                            const entity_funcs_t *b);

#endif