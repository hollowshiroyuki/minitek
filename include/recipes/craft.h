/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef CRAFT_H_
#define CRAFT_H_

#include "recipes/recipe.h"

typedef struct craft_s
{
    recipe_t *workbench;
    recipe_t *anvil;
    recipe_t *oven;
    recipe_t *furnace;
} craft_t;

craft_t *craft_create(void);
recipe_t *workbench_recipes_create(void);
recipe_t *anvil_recipes_create(void);
recipe_t *oven_recipes_create(void);
recipe_t *furnace_recipes_create(void);
void craft_destroy(craft_t *self);

#endif