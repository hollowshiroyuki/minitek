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

entity_t *slime_create(int level)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->mob.ent = new;
    new->mob.sli.mob = &new->mob;
    new->mob.health = 10;
    new->id = E_SLIME;
    new->pos = (sfVector2i){random_int(1024), random_int(1024)};
    entity_funcs_combine(&new->funcs, &slime_funcs, &mob_funcs);
    return (new);
}