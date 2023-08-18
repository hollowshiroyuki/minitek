/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/flower.h"

const tile_t flower = {
    .id = T_FLOWER,
    .water = false,
    .sand = false,
    .grass = true,
    .lava = false,
    .render = flower_render
};