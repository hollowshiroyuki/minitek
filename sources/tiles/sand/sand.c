/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/sand.h"

const tile_t sand = {
    .id = T_SAND,
    .water = false,
    .sand = true,
    .grass = false,
    .lava = false,
    .render = sand_render
};