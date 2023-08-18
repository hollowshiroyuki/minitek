/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ITEM_H_
#define ITEM_H_

#include "resources/tool_item.h"
#include "item_funcs.h"

typedef struct item_s item_t;
typedef struct item_s
{
    int id;
    union {
        tool_item_t tool;
        //resource_item_t res;
        //furniture_item_t fur;
    };
    item_funcs_t funcs;
    item_t *next;
} item_t;

#endif