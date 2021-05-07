/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include <stdio.h>
#include "scenes.h"
#include "universe.h"
#include "entities/workbench.h"
#include "resources/resources.h"

void game_init(engine_t *engine)
{
    game_data_t *data = &engine->game_data;
    menu_data_t *menu = &engine->menu_data;

    data->universe = menu->universe;
    data->input = menu->input;
    data->screen = &menu->screen;
}