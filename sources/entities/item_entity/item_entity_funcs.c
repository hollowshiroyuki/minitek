/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/item_entity.h"

const entity_funcs_t item_entity_funcs = {
    .draw = item_entity_draw,
    .destroy = item_entity_destroy,
    .tick = item_entity_tick,
    .touched_by = item_entity_touched_by
};