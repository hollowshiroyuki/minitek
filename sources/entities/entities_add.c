/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

void entities_add(entity_t **self, entity_t *entity)
{
    entity_t *tmp = *self;

    if (!tmp) {
        *self = entity;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = entity;
}