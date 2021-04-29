/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entity_funcs.h"
#include "entities/entity.h"

void entity_funcs_combine(entity_funcs_t *r,
                            const entity_funcs_t *pa,
                            const entity_funcs_t *pb)
{
    if (!r || !pa || !pb)
        return;
    r->hurt = pa->hurt ?: pb->hurt ?: entity_funcs.hurt;
    r->move = pa->move ?: pb->move ?: entity_funcs.move;
    r->move_axis = pa->move_axis ?: pb->move_axis ?: entity_funcs.move_axis;
}