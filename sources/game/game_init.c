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
#include "menus/title_menu.h"
#include "entities/workbench.h"

void game_init(engine_t *engine)
{
    game_data_t *data = &engine->game_data;
    entity_t *workbench = workbench_create();

    screen_init(&data->screen, &engine->assets, engine->window);
    data->input = input_create();
    data->universe = universe_create((sfVector2i){256, 256}, data->input, 42);
    universe_set_menu(data->universe, title_menu_create());
}