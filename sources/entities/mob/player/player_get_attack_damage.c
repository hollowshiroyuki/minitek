/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "random.h"
#include "entities/entity.h"
#include "entities_id.h"
#include "resources/item.h"

int player_get_attack_damage(entity_t *self, entity_t *entity)
{
    int dmg = random_int(3) + 1;
    item_t *item = self->mob.pla.active_item;

    if (item) {
        dmg += (item->funcs.attack_bonus)(item, entity);
    }
    return (dmg);
}