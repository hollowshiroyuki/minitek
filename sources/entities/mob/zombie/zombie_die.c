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
#include "resources/resources.h"

void zombie_die(entity_t *self)
{
    int count = random_int(2) + 1;
    item_t *resource;
    entity_t *item_entity;
    sfVector2i item_pos;

    for (int i = 0; i < count; i++) {
        item_pos.x = self->pos.x + random_int(11) - 5;
        item_pos.y = self->pos.y + random_int(11) - 5;
        resource = resource_item_create((resource_t *)&r_cloth, 1);
        item_entity = item_entity_create(resource, item_pos);
        floor_add(self->floor, item_entity);
    }
}