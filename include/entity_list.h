/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ENTITY_LIST_H_
#define ENTITY_LIST_H_

#include "entities.h"

typedef struct entity_list_s entity_list_t;
typedef struct entity_list_s
{
    int type;
    void *data;
    entity_list_t *next;
} entity_list_t;

#endif