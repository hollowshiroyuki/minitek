/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "universe.h"

void game_destroy(engine_t *engine)
{
    game_data_t *data = &engine->game_data;

    if (data->universe)
        universe_destroy(data->universe);
    screen_destroy(&data->screen);
}