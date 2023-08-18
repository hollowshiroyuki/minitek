/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "rpg.h"
#include "scenes.h"
#include "menus/menu.h"

void main_menu_update(engine_t *engine)
{
    menu_data_t *data = &engine->menu_data;
    game_data_t *game = &engine->game_data;

    input_tick(data->input);
    (data->menu->funcs.tick)(data->menu);
    if (data->stop == true)
        engine->state = EN_STOP;
    if (!data->stop && data->universe) {
        (engine->menu_data.menu->funcs.destroy)(engine->menu_data.menu);
        engine->menu_data.menu = 0;
        engine->active_scene = S_GAME;
        (*scenes[engine->active_scene].init)(engine);
    }
}