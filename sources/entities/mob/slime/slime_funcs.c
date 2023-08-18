/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/slime.h"

const entity_funcs_t slime_funcs = {
    .draw = slime_draw,
    .tick = slime_tick,
    .die = slime_die,
    .touched_by = slime_touched_by
};