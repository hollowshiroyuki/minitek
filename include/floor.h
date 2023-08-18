/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FLOOR_H_
#define FLOOR_H_

#include <SFML/Graphics.h>
#include "entities.h"
#include "tiles/tile.h"

typedef struct floor_s
{
    int depth;
    sfVector2i size;
    int *tiles;
    int *data;
    int tickCount;
    int monster_density;
    entity_t *player;
    entity_t *entities;
    entity_t ***entities_in_tiles;
    entity_t **entities_row;
} floor_t;

floor_t *floor_create(sfVector2i size, int depth, floor_t *parent);
void floor_destroy(floor_t *self);
void floor_tick(floor_t *self);
void floor_insert_entity(floor_t *self, sfVector2i pos, entity_t *entity);
void floor_try_spawn(floor_t *self, int tries);
void floor_draw_background(floor_t *fl, sfVector2i scroll, screen_t *screen);
void floor_draw_entities(floor_t *fl, sfVector2i of, screen_t *screen);
tile_t floor_get_tile(floor_t *self, sfVector2i pos);
void floor_set_tile(floor_t *self, sfVector2i pos, const tile_t tile, int data);
int floor_get_data(floor_t *self, sfVector2i pos);
void floor_set_data(floor_t *self, sfVector2i pos, int data);
void floor_add(floor_t *self, entity_t *entity);
void floor_sort_and_draw(floor_t *self, screen_t *screen, entity_t **list);
void floor_entities_row_clear(entity_t **row, int len);
entity_t **floor_get_entities(floor_t *self, sfVector2i pos1, sfVector2i pos2);
void floor_insert_entity(floor_t *self, sfVector2i p, entity_t *entity);
void floor_remove_entity(floor_t *self, sfVector2i p, entity_t *entity);
//void floor_remove(floor_t *self, entity_t *entity);

#endif