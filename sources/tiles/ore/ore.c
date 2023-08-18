/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/ore.h"

const tile_t iron_ore = {
    .id = T_IRON,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .variant = 0,
    .render = ore_render
};

const tile_t lapis_ore = {
    .id = T_LAPIS,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .variant = 1,
    .render = ore_render
};

const tile_t gold_ore = {
    .id = T_GOLD,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .variant = 2,
    .render = ore_render
};

const tile_t gem_ore = {
    .id = T_GEM,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .variant = 3,
    .render = ore_render
};