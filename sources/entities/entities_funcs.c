/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/zombie.h"
#include "entities/mob.h"
#include "entities/slime.h"
#include "entities/entity.h"
#include "entity_funcs.h"

const entity_funcs_t *entities_funcs[] = {
    &entity_funcs,
    &mob_funcs,
    &slime_funcs,
    &zombie_funcs
};