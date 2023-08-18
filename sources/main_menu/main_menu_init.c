/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "index_gui.h"
#include "universe.h"

void main_menu_init(engine_t *engine)
{
    menu_data_t *data = &engine->menu_data;
    game_data_t *game = &engine->game_data;

    screen_init(&data->screen, &engine->assets, engine->window);
    data->input = input_create();
    data->menu = title_menu_create(data);
    menu_init(data->menu, game->universe, data->input);
    data->init = true;
    data->stop = false;
}
