/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "entity_funcs.h"

extern const entity_funcs_t *entities_funcs[];

void entities_draw(entity_t *list, screen_t *screen);

#endif