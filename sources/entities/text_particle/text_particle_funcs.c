/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/text_particle.h"

const entity_funcs_t text_particle_funcs = {
    .draw = text_particle_draw,
    .tick = text_particle_tick
};