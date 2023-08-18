/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "resources/item.h"
#include "items_id.h"
#include "entities/entity.h"
#include "hsy.h"

item_t *furniture_item_create(entity_t *furniture)
{
    item_t *new = malloc(sizeof(item_t));

    memset(new, 0, sizeof(item_t));
    new->id = I_FURNITURE;
    new->fur.furniture = furniture;
    item_funcs_combine(&new->funcs, &furniture_item_funcs);
    return (new);
}