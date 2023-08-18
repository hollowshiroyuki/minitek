/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include <stdio.h>
#include "entities_id.h"

void entities_remove(entity_t **self, entity_t *entity)
{
    entity_t *tmp = *self;
    entity_t *prv = NULL;

    if (tmp == entity) {
        *self = tmp->next;
        if (tmp->id != E_MOB && tmp->mob.id != MB_PLAYER)
            (*tmp->funcs.destroy)(tmp);
        return;
    } else {
        while (tmp && tmp != entity) {
            prv = tmp;
            tmp = tmp->next;
        }
        if (tmp) {
            prv->next = tmp->next;
            if (tmp->id != E_MOB && tmp->mob.id != MB_PLAYER) {
                (*tmp->funcs.destroy)(tmp);
            }
        }
    }
}