/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FOOD_RESOURCE_H_
#define FOOD_RESOURCE_H_

#include <SFML/Graphics.h>
typedef struct resource_s resource_t;
typedef struct entity_s entity_t;
typedef struct tile_s tile_t;

typedef struct food_resource_s
{
    int heal;
    int stamina_cost;
} food_resource_t;

bool food_interact(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla);

#endif