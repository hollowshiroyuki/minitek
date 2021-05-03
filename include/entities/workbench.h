/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef WORKBENCH_H_
#define WORKBENCH_H_

#include "entity_funcs.h"

typedef struct entity_s entity_t;

extern const entity_funcs_t workbench_funcs;

typedef struct workbench_s
{
} workbench_t;

entity_t *workbench_create(void);
bool workbench_use(entity_t *self, entity_t *player, int dir);

#endif