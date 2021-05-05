/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "tiles/tile.h"
#include "tiles_id.h"
#include "tiles/tree.h"

const tile_t tree = {
    .id = T_TREE,
    .water = false,
    .sand = false,
    .grass = true,
    .lava = false,
    .may_pass = tree_may_pass,
    .render = tree_render,
    .hurt = tree_hurt,
    .interact = tree_interact
};