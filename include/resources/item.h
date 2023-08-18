/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ITEM_H_
#define ITEM_H_

#include "resources/tool_item.h"
#include "resources/resource_item.h"
#include "resources/furniture_item.h"
#include "item_funcs.h"

typedef struct item_s item_t;
typedef struct item_s
{
    int id;
    union {
        tool_item_t tool;
        resource_item_t res;
        furniture_item_t fur;
    };
    item_funcs_t funcs;
    item_t *next;
} item_t;

void item_list_add(item_t **list, item_t *new, int pos);
int item_list_size(item_t *list);
void item_list_remove(item_t **list, item_t *item);
void item_save(item_t *self, int fd);

#endif