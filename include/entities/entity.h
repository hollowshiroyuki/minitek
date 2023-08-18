/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "entity_funcs.h"
#include "entities/mob.h"
#include "entities/furniture.h"

typedef struct floor_s floor_t;

extern const entity_funcs_t entity_funcs;

typedef struct entity_s
{
    int id;
    sfVector2i pos;
    sfVector2i box;
    floor_t *floor;
    bool removed;
    union {
        mob_t mob;
        furniture_t fur;
    };
    entity_funcs_t funcs;
    entity_t *next;
} entity_t;

void entity_tick(entity_t *self);
void entity_draw(entity_t *self, screen_t *win);
void entity_destroy(entity_t *self);
void entity_hurt(entity_t *self, entity_t *entity, int dmg, int dir);
bool entity_move(entity_t *self, sfVector2i pos);
bool entity_move_axis(entity_t *self, sfVector2i pos);
void entity_touched_by(entity_t *self, entity_t *entity);
bool entity_is_blockable_by(entity_t *self, entity_t *entity);
void entity_touch_item(entity_t *self, entity_t *item);
bool entity_can_swim(entity_t *self);
bool entity_interact(entity_t *self, entity_t *entity, item_t *item, int dir);
bool entity_use(entity_t *self, entity_t *entity, int dir);
bool entity_instance_of(entity_t *self, int id);
bool entity_intersects(entity_t *self, sfVector2i pos1, sfVector2i pos2);
void entity_hurt_tile(entity_t *self, tile_t tile, sfVector2i pos, int dmg);
bool entity_find_start_pos(entity_t *self, floor_t *floor);
bool entity_blocks(entity_t *self, entity_t *entity);
void entities_add(entity_t **self, entity_t *entity);
void entity_init(entity_t *self, floor_t *floor);
int entities_count(entity_t *list);
void entities_add_all(entity_t **dest, entity_t **src);
void entities_remove(entity_t **self, entity_t *entity);
void entity_heal(entity_t *self, int heal);

#endif