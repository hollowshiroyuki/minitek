/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

bool entity_move(entity_t *self, sfVector2i pos)
{
    sfVector2i off = {0};
    bool stop = false;

    if (pos.x || pos.y) {
        if (pos.x && entity_move_axis(self, (sfVector2i){pos.x, 0}))
            stop = true;
        if (pos.y && entity_move_axis(self, (sfVector2i){0, pos.y}))
            stop = true;
        return (!stop);
    }
    return (true);
}