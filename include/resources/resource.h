/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <stdbool.h>
#include "resources/food_resource.h"
#include "resources/plant_resource.h"

typedef struct entity_s entity_t;

typedef struct resource_s resource_t;
typedef struct resource_s
{
    int id;
    char *name;
    int tex;
    union {
        food_resource_t food;
        plant_resource_t plant;
    };
    bool (*interact)(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla);
} resource_t;

bool resource_interact(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla);

#endif