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
#include "inventory.h"

void init_default_values(entity_t *new)
{
    new->id = E_PLAYER;
    new->mob.ent = new;
    new->mob.pla.mob = &new->mob;
    new->mob.health = 10;
    new->mob.max_health = 10;
    new->mob.pla.max_stamina = 10;
    new->mob.pla.stamina = 9999;
    new->box = (sfVector2i){4, 4};
}

entity_t *player_create(universe_t *universe, input_t *input)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    init_default_values(new);
    new->mob.pla.input = input;
    new->floor = universe->active_floor;
    new->mob.pla.universe = universe;
    new->mob.pla.inventory = inventory_create(10);
    entity_funcs_combine(&new->funcs, &player_funcs, &mob_funcs);
    return (new);
}