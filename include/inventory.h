/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "resources/item.h"
#include "resources/resource.h"

typedef struct inventory_s
{
    item_t *items;
    int item_count;
    int capacity;
} inventory_t;

inventory_t *inventory_create(int size);
item_t *inventory_remove_item(inventory_t *self, int pos);
void inventory_add(inventory_t *self, item_t *item);
void inventory_add_pos(inventory_t *self, item_t *item, int pos);
item_t *inventory_find_resource(inventory_t *self, resource_t *res);
bool inventory_has_resources(inventory_t *self, resource_t *res, int count);
bool inventory_remove_resource(inventory_t *self, resource_t *res, int count);
int inventory_count(inventory_t *self, item_t *item);
void inventory_destroy(inventory_t *self);

#endif