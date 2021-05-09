/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "resources/resources.h"
#include "resources_id.h"

resource_t *resource_get(int resource_id)
{
    int tile_id = 0;

    for (int i = 0; i < R_COUNT && resources[i]; i++) {
        if (resources[i] && resources[i]->id == resource_id)
            return ((resource_t *)resources[i]);
    }
    return ((resource_t *)&r_dirt);
}