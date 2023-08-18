/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/mob.h"

const entity_funcs_t mob_funcs = {
    .tick = mob_tick,
    .hurt = mob_hurt,
    .do_hurt = mob_do_hurt,
    .move = mob_move,
    .hurt_tile = mob_hurt_tile,
    .find_start_pos = mob_find_start_pos
};