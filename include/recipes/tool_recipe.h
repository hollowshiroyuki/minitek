/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TOOL_RECIPE_H_
#define TOOL_RECIPE_H_

#include "recipe_funcs.h"

extern const recipe_funcs_t tool_recipe_funcs;

typedef struct tool_type_s tool_type_t;
typedef struct recipe_s recipe_t;
typedef struct entity_s entity_t;

typedef struct tool_recipe_s
{
    tool_type_t *type;
    int level;
} tool_recipe_t;

recipe_t *tool_recipe_create(tool_type_t *type, int level);
void tool_recipe_craft(recipe_t *self, entity_t *player);
void tool_recipe_destroy(recipe_t *self);
void tool_recipe_craft(recipe_t *self, entity_t *player);

#endif