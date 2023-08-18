/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/furniture.h"

const entity_funcs_t furniture_funcs = {
    .tick = furniture_tick,
    .draw = furniture_draw,
    .blocks = furniture_blocks,
    .touched_by = furniture_touched_by
};