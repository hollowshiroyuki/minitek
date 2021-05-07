/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "universe.h"

void game_event(engine_t *engine, sfEvent *event)
{
    game_data_t *data = &engine->game_data;

    if (engine->game_data.universe->input)
        input_tick(engine->game_data.universe->input);
}