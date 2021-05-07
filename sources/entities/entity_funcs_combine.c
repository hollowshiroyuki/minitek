/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entity_funcs.h"
#include "entities/entity.h"

static void combine_2(entity_funcs_t *r, const entity_funcs_t *pa,
                        const entity_funcs_t *pb)
{
    r->heal = pa->heal ?: pb->heal ?: entity_funcs.heal;
    r->die = pa->die ?: pb->die ?: entity_funcs.die;
    r->do_hurt = pa->do_hurt ?: pb->do_hurt ?: entity_funcs.do_hurt;
    r->tick = pa->tick ?: pb->tick ?: entity_funcs.tick;
    r->draw = pa->draw ?: pb->draw ?: entity_funcs.draw;
    r->destroy = pa->destroy ?: pb->destroy ?: entity_funcs.destroy;
    r->hurt = pa->hurt ?: pb->hurt ?: entity_funcs.hurt;
    r->hurt_tile = pa->hurt_tile ?: pb->hurt_tile ?: entity_funcs.hurt_tile;
    r->move = pa->move ?: pb->move ?: entity_funcs.move;
}

void entity_funcs_combine(entity_funcs_t *r,
                            const entity_funcs_t *pa,
                            const entity_funcs_t *pb)
{
    if (!r || !pa || !pb)
        return;
    entity_funcs_t *ef = (entity_funcs_t *)&entity_funcs;
    r->move_axis = pa->move_axis ?: pb->move_axis ?: entity_funcs.move_axis;
    r->touched_by = pa->touched_by ?: pb->touched_by ?: entity_funcs.touched_by;
    r->is_block_by = pa->is_block_by ?: pb->is_block_by ?: ef->is_block_by;
    r->touch_item = pa->touch_item ?: pb->touch_item ?: entity_funcs.touch_item;
    r->can_swim = pa->can_swim ?: pb->can_swim ?: entity_funcs.can_swim;
    r->interact = pa->interact ?: pb->interact ?: entity_funcs.interact;
    r->use = pa->use ?: pb->use ?: entity_funcs.use;
    r->intersects = pa->intersects ?: pb->intersects ?: entity_funcs.intersects;
    r->start_pos = pa->start_pos ?: pb->start_pos ?: entity_funcs.start_pos;
    r->blocks = pa->blocks ?: pb->blocks ?: entity_funcs.blocks;
    r->init = pa->init ?: pb->init ?: entity_funcs.init;
    combine_2(r, pa, pb);
}