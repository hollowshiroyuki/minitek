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
    r->draw = pa->draw ?: pb->draw ?: entity_funcs.draw;
    r->tick = pa->tick ?: pb->tick ?: entity_funcs.tick;
    r->blocks = pa->blocks ?: pb->blocks ?: entity_funcs.blocks;
    r->destroy = pa->destroy ?: pb->destroy ?: entity_funcs.destroy;
}