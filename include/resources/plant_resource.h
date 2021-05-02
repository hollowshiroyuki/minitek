/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef PLANTABLE_RESOURCE_H_
#define PLANTABLE_RESOURCE_H_

#include "tiles/tile.h"

typedef struct plant_resource_s
{
    tile_t *sources[5];
    tile_t *target;
} plant_resource_t;

bool plant_interact(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla);

#endif