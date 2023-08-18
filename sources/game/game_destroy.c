/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"
#include "scenes.h"
#include "universe.h"

void game_destroy(engine_t *engine)
{
    game_data_t *data = &engine->game_data;
    menu_data_t *menu = &engine->menu_data;

    if (data->universe) {
        universe_destroy(data->universe);
        data->universe = 0;
        menu->universe = 0;
    }
}