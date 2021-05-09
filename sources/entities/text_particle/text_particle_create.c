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

entity_t *text_particle_create(int msg, sfVector2i pos, sfColor color)
{
    entity_t *new = malloc(sizeof(entity_t));
    entity_funcs_t *funcs = (entity_funcs_t *)&text_particle_funcs;

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->id = E_MOB;
    new->mob.id = MB_ZOMBIE;
    new->mob.ent = new;
    new->pos = pos;
    new->tpart.a.x = random_gaussian() * 0.3;
    new->tpart.a.y = random_gaussian() * 0.2;
    new->tpart.a.z = random_float() * 0.7 + 2;
    new->tpart.b = (sfVector3f){pos.x, pos.y, 2};
    new->tpart.color = color;
    new->tpart.msg = msg;
    entity_funcs_combine(&new->funcs, funcs, funcs);
    return (new);
}