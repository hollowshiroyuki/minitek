/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "universe.h"
#include "level_gen.h"
#include "floor.h"
#include "random.h"

universe_t *universe_create(sfVector2i size, input_t *input, int seed, char *n)
{
    universe_t *new = malloc(sizeof(universe_t));

    if (!new)
        return (0);
    memset(new, 0, sizeof(universe_t));
    new->input = input;
    srand(seed);
    new->floors[0] = floor_create(size, 0, 0);
    new->floors[1] = floor_create(size, 1, new->floors[0]);
    new->floors[2] = floor_create(size, 2, new->floors[1]);
    new->active_floor = new->floors[1];
    new->player = player_create(new, input);
    new->craft = craft_create();
    (*new->player->funcs.start_pos)(new->player, new->active_floor);
    floor_add(new->active_floor, new->player);
    new->running = true;
    return (new);
}