/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "universe.h"

void game_init(engine_t *engine)
{
    game_data_t *data = &engine->game_data;

    screen_init(&data->screen, &engine->assets, engine->window);
    data->universe = universe_create((sfVector2i){256, 256});
}