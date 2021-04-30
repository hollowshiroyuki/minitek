/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entities_id.h"
#include "entities/entity.h"
#include "universe.h"

entity_t *player_create(universe_t *universe, input_t *input)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->mob.ent = new;
    new->mob.pla.mob = &new->mob;
    new->id = E_PLAYER;
    new->mob.pla.input = input;
    new->floor = universe->active_floor;
    new->mob.pla.universe = universe;
    entity_funcs_combine(&new->funcs, &player_funcs, &mob_funcs);
    return (new);
}