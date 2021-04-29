/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "universe.h"
#include "level_gen.h"
#include "floor.h"

universe_t *universe_create(sfVector2i size)
{
    universe_t *new = malloc(sizeof(universe_t));

    if (!new)
        return (0);
    for (int i = 0; i < 16; i++)
        new->floors[i] = 0;
    new->floors[0] = floor_create(size, 0, 0);
    new->floors[1] = floor_create(size, 1, new->floors[0]);
    new->floors[2] = floor_create(size, 2, new->floors[1]);
    new->active_floor = new->floors[1];
    //universe->player = player_create(new);
    new->running = true;
    new->tick_count = 0;
    return (new);
}