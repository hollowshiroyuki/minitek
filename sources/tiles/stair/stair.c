/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/stair.h"

const tile_t stair_up = {
    .id = T_STAIRUP,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = stair_render,
    .variant = 1
};

const tile_t stair_down = {
    .id = T_STAIRDOWN,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = stair_render,
    .variant = 0
};