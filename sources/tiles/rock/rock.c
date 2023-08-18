/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/rock.h"

const tile_t rock = {
    .id = T_ROCK,
    .water = false,
    .sand = false,
    .grass = false,
    .lava = false,
    .render = rock_render,
    .may_pass = rock_may_pass,
    .hurt = rock_hurt,
    .interact = rock_interact
};