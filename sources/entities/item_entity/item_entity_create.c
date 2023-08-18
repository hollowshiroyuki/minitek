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

entity_t *item_entity_create(item_t *item, sfVector2i pos)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(entity_t));
    new->id = E_ITEM;
    new->box = (sfVector2i){3, 3};
    new->itm.item = item;
    new->pos = pos;
    new->itm.b = (sfVector3f){pos.x, pos.y, 2};
    new->itm.a.x = random_float() * 0.3;
    new->itm.a.y = random_float() * 0.2;
    new->itm.a.z = random_float() * 0.7 + 1;
    new->itm.lifetime = 60 * 10 + random_int(60);
    entity_funcs_combine(&new->funcs, &item_entity_funcs, &item_entity_funcs);
    return (new);
}