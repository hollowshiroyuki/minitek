/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TEXT_PARTICLE_H_
#define TEXT_PARTICLE_H_

#include "entity_funcs.h"

typedef struct mob_s mob_t;
typedef struct entity_s entity_t;

extern const entity_funcs_t text_particle_funcs;

typedef struct text_particle_s
{
    sfVector3f a;
    sfVector3f b;
    int time;
    int msg;
    sfColor color;
} text_particle_t;

entity_t *text_particle_create(int msg, sfVector2i pos, sfColor color);
void text_particle_draw(entity_t *self, screen_t *screen);
void text_particle_tick(entity_t *self);
void text_particle_destroy(entity_t *self);

#endif