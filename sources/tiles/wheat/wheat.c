/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/wheat.h"

const tile_t wheat = {
    .id = T_WHEAT,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = wheat_render
};