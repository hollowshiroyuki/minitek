/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RECIPE_FUNCS_H_
#define RECIPE_FUNCS_H_

#include "entities/entity.h"

typedef struct recipe_s recipe_t;

typedef struct recipe_funcs_s
{
    void (*add_cost)(recipe_t *self, resource_t *res, int count);
    void (*check_can_craft)(recipe_t *self, entity_t *player);
    void (*craft)(recipe_t *self, entity_t *player);
    void (*deduct_cost)(recipe_t *self, entity_t *player);
    void (*destroy)(recipe_t *self);
} recipe_funcs_t;

void recipe_funcs_combine(recipe_funcs_t *d, const recipe_funcs_t *r_f);

#endif