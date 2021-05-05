/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/carrot.h"

const tile_t carrot = {
    .id = T_CARROT,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = carrot_render
};