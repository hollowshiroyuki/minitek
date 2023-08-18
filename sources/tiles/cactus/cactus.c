/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/cactus.h"

const tile_t cactus = {
    .id = T_CACTUS,
    .water = false,
    .sand = true,
    .grass = false,
    .lava = false,
    .render = cactus_render,
    .bump = cactus_bump,
    .may_pass = cactus_may_pass
};