/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/water.h"

const tile_t water = {
    .id = T_WATER,
    .water = true,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = water_render
};