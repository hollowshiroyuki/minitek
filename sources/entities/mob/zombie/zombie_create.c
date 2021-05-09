/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "entities_id.h"
#include "random.h"
#include <stdio.h>
#include "entities/entity.h"

entity_t *zombie_create(int level)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->id = E_MOB;
    new->mob.id = MB_ZOMBIE;
    new->mob.ent = new;
    new->mob.max_health = level * level * 10;
    new->mob.zom.mob = &new->mob;
    new->mob.health = new->mob.max_health;
    new->box = (sfVector2i){4, 3};
    new->pos = (sfVector2i){random_int(1024), random_int(1024)};
    entity_funcs_combine(&new->funcs, &zombie_funcs, &mob_funcs);
    return (new);
}