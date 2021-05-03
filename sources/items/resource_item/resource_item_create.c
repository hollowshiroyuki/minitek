/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include "resources/item.h"
#include "resources/resource_item.h"
#include "items_id.h"
#include "hsy.h"

item_t *resource_item_create(const resource_t *res, int count)
{
    item_t *new = malloc(sizeof(item_t));

    memset(new, 0, sizeof(item_t));
    new->id = I_RESOURCE;
    new->res.count = count ?: 1;
    new->res.resource = (resource_t *)res;
    item_funcs_combine(&new->funcs, &resource_item_funcs);
    return (new);
}