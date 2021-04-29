/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/dirt.h"

const tile_t dirt = {
    .id = T_DIRT,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = dirt_render
};