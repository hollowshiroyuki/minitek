/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resources/resource.h"

extern const resource_t r_dirt;
extern const resource_t r_bread;
extern const resource_t r_wood;
extern const resource_t r_stone;
extern const resource_t r_apple;
extern const resource_t r_slime;
extern const resource_t r_cloth;
extern const resource_t r_seeds;

extern const resource_t *resources[];

resource_t *resource_get(int resource_id);

#endif