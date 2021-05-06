/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/zombie.h"

const entity_funcs_t zombie_funcs = {
    .draw = zombie_draw,
    .tick = zombie_tick,
    .die = zombie_die,
    .touched_by = zombie_touched_by
};