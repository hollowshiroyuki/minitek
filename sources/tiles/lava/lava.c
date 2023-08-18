/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/lava.h"

const tile_t lava = {
    .id = T_LAVA,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = true,
    .render = lava_render,
    .may_pass = lava_may_pass,
    .tick = lava_tick
};