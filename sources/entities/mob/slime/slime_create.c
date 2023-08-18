/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "entities_id.h"
#include "entities/entity.h"

entity_t *slime_create(void)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    new->mob.ent = new;
    new->mob.sli.mob = &new->mob;
    new->id = E_SLIME;
    entity_funcs_combine(&new->funcs, &slime_funcs, &mob_funcs);
    return (new);
}