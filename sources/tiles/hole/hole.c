/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles/hole.h"
#include "tiles_id.h"

const tile_t hole = {
    .id = T_HOLE,
    .water = true,
    .sand = false,
    .grass = false,
    .lava = true,
    .render = hole_render,
    .may_pass = hole_may_pass
};