/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/grass.h"

const tile_t grass = {
    .id = T_GRASS,
    .water = false,
    .sand = false,
    .grass = true,
    .lava = false,
    .render = grass_render
};