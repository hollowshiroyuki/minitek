/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RECIPE_H_
#define RECIPE_H_

#include "recipes/tool_recipe.h"
#include "recipes/furniture_recipe.h"
#include "recipes/resource_recipe.h"
#include "recipe_funcs.h"

extern const recipe_funcs_t recipe_funcs;

typedef struct recipe_s recipe_t;
typedef struct recipe_s
{
    int id;
    item_t *cost;
    item_t *result;
    bool can_craft;
    union {
        tool_recipe_t tool;
        furniture_recipe_t fur;
        resource_recipe_t res;
    };
    recipe_funcs_t funcs;
    recipe_t *next;
} recipe_t;

void recipe_add(recipe_t **list, recipe_t *new);
void recipe_add_cost(recipe_t *self, resource_t *res, int count);

recipe_t *recipe_create(item_t *item);
void recipe_check_can_craft(recipe_t *self, entity_t *player);
void recipe_render_inventory(recipe_t *self, screen_t *scr, sfVector2i pos);
void recipe_craft(recipe_t *self, entity_t *player);
void recipe_deduct_cost(recipe_t *self, entity_t *player);
void recipe_destroy(recipe_t *self);
void recipe_list_destroy(recipe_t *list);
void recipe_init(recipe_t *self, item_t *item);

void recipe_list_delink(recipe_t *list);
recipe_t *recipe_list_copy(recipe_t *list);
void recipe_list_sort(recipe_t **list);
int recipe_list_size(recipe_t *list);
recipe_t *recipe_list_get(recipe_t *recipe, int pos);
#endif