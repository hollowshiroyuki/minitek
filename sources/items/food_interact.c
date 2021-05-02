/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/resource.h"
#include "entities/entity.h"

bool food_interact(resource_t *s, tile_t tile, sfVector2i p, entity_t *pla)
{
    int c = s->food.stamina_cost;

    if (pla->mob.health < pla->mob.max_health && player_pay_stamina(pla, c)) {
        (pla->funcs.heal)(pla, s->food.heal);
    }
    return (false);
}