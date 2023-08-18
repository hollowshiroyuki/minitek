/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FURNITURE_RECIPE_H_
#define FURNITURE_RECIPE_H_

#include "recipe_funcs.h"

extern const recipe_funcs_t furniture_recipe_funcs;

typedef struct recipe_s recipe_t;
typedef struct entity_s entity_t;

typedef struct furniture_recipe_s
{
    entity_t *(*create_furniture)(void);
} furniture_recipe_t;

recipe_t *furniture_recipe_create(entity_t *(*func)());
void furniture_recipe_craft(recipe_t *self, entity_t *player);
void furniture_recipe_destroy(recipe_t *self);
void furniture_recipe_craft(recipe_t *self, entity_t *player);

#endif