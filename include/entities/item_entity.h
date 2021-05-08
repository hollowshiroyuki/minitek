/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ITEM_ENTIY_H_
#define ITEM_ENTIY_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "entity_funcs.h"

extern const entity_funcs_t item_entity_funcs;

typedef struct entity_s entity_t;

typedef struct item_entity_s
{
    int id;
    int lifetime;
    sfVector3f a;
    sfVector3f b;
    item_t *item;
    int time;
    bool picked_up;
} item_entity_t;

entity_t *item_entity_create(item_t *item, sfVector2i pos);
void item_entity_init(entity_t *self, char *name);
void item_entity_tick(entity_t *self);
void item_entity_draw(entity_t *self, screen_t *screen);
bool item_entity_blocks(entity_t *self, entity_t *entity);
void item_entity_touched_by(entity_t *self, entity_t *entity);
void item_entity_take(entity_t *self, entity_t *player);
void item_entity_destroy(entity_t *self);
void item_entity_save(entity_t *self, int fd);

#endif