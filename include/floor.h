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
    entity_t *player;
    entity_t *entities;
} floor_t;

floor_t *floor_create(sfVector2i size, int depth, floor_t *parent);
void floor_destroy(floor_t *self);
void floor_tick(floor_t *self);
void floor_try_spawn(floor_t *self, int tries);
void floor_draw_background(floor_t *fl, sfVector2i scroll, screen_t *screen);
void floor_render_entities(floor_t *fl, sfVector2i of, sfRenderWindow *win);
tile_t floor_get_tile(floor_t *self, sfVector2i pos);
void floor_set_tile(floor_t *self, sfVector2i pos, const tile_t tile, int data);
int floor_get_data(floor_t *self, sfVector2i pos);
void floor_set_data(floor_t *self, sfVector2i pos, int data);
//void floor_add(floor_t *self, entity_t *entity);
//void floor_remove(floor_t *self, entity_t *entity);


#endif