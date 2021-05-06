/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RESOURCE_RECIPE_H_
#define RESOURCE_RECIPE_H_

#include "recipe_funcs.h"

extern const recipe_funcs_t resource_recipe_funcs;

typedef struct recipe_s recipe_t;
typedef struct entity_s entity_t;

typedef struct resource_recipe_s
{
    int count;
    resource_t *res;
} resource_recipe_t;

recipe_t *resource_recipe_create(resource_t *res, int count);
void resource_recipe_craft(recipe_t *self, entity_t *player);
void resource_recipe_destroy(recipe_t *self);

#endif