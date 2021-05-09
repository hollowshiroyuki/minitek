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

extern const entity_funcs_t furniture_funcs;

typedef struct entity_s entity_t;

enum {
    F_WORKBENCH,
    F_OVEN,
    F_ANVIL,
    F_FURNACE,
    F_COUNT
};

typedef struct furniture_type_s
{
    int id;
    char *name;
    int tex;
    entity_funcs_t *funcs;
} furniture_type_t;

extern const furniture_type_t workbench_type;
extern const furniture_type_t oven_type;
extern const furniture_type_t *furnitures_types[];

typedef struct furniture_s
{
    int id;
    char *name;
    int push_time;
    int push_dir;
    int tex;
    entity_t *player;
    entity_t *ent;
} furniture_t;

void furniture_init(entity_t *self, char *name);
void furniture_tick(entity_t *self);
void furniture_draw(entity_t *self, screen_t *screen);
bool furniture_blocks(entity_t *self, entity_t *entity);
void furniture_touched_by(entity_t *self, entity_t *entity);
void furniture_take(entity_t *self, entity_t *player);
void furniture_destroy(entity_t *self);
void furniture_save(entity_t *self, int fd);
entity_t *furniture_create(int furniture_id);

#endif