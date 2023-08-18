/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/farmland.h"

const tile_t farmland = {
    .id = T_FARMLAND,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = farmland_render
};