/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FURNITURE_H_
#define FURNITURE_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "entity_funcs.h"
//#include "entities/workbench.h"

extern const entity_funcs_t furnitures_funcs;

typedef struct entity_s entity_t;

typedef struct furniture_s
{
    char *name;
    int push_time;
    int push_dir;
    int tex;
    entity_t *player;
    union {
    };
    entity_t *ent;
} furniture_t;

void furniture_init(entity_t *self, char *name);
void furniture_tick(entity_t *self);
void furniture_draw(entity_t *self, screen_t *screen);
bool furniture_blocks(entity_t *self, entity_t *entity);
void furniture_touched_by(entity_t *self, entity_t *entity);
void furniture_take(entity_t *self, entity_t *player);

#endif