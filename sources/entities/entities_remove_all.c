/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include <stdio.h>
#include "entities_id.h"

static void remove_entity(entity_t **list, entity_t *entity)
{
    for (int i = 0; list[i]; i++) {
        if (list[i] == entity) {
            list[i] = 0;
            for (int j = i + 1; list[j]; j++) {
                list[j - 1] = list[j];
            }
            return;
        }
    }
}

void entities_remove_all(entity_t **self, entity_t **to_remove)
{
    for (int i = 0; to_remove[i]; i++) {
        remove_entity(self, to_remove[i]);
    }
}