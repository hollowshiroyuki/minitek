/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "item_funcs.h"

void item_funcs_combine(item_funcs_t *d, const item_funcs_t *i_f)
{
    d->attack_bonus = i_f->attack_bonus ?: item_funcs.attack_bonus;
    d->can_attack = i_f->can_attack ?: item_funcs.can_attack;
    d->draw_icon = i_f->draw_icon ?: item_funcs.draw_icon;
    d->draw_inventory = i_f->draw_inventory ?: item_funcs.draw_inventory;
    d->get_name = i_f->get_name ?: item_funcs.get_name;
    d->get_tex = i_f->get_tex ?: item_funcs.get_tex;
    d->interact = i_f->interact ?: item_funcs.interact;
    d->interact_tile = i_f->interact_tile ?: item_funcs.interact_tile;
    d->is_depleted = i_f->is_depleted ?: item_funcs.is_depleted;
    d->matches = i_f->matches ?: item_funcs.matches;
    d->on_take = i_f->on_take ?: item_funcs.on_take;
    d->destroy = i_f->destroy ?: item_funcs.destroy;
}