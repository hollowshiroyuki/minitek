/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include <stdio.h>
#include "universe.h"

void game_update(engine_t *engine)
{
    bool to_main_menu = 0;

    if (engine->game_data.universe && engine->game_data.universe->running) {
        universe_tick(engine->game_data.universe);
    } else {
        if (engine->game_data.universe->to_main_menu == true) {
            engine->menu_data.menu = title_menu_create(&engine->menu_data);
            engine->menu_data.menu->input = engine->game_data.universe->input;
            engine->active_scene = 0;
        } else {
            engine->state = EN_STOP;
        }
        universe_destroy(engine->game_data.universe);
        engine->game_data.universe = 0;
        engine->menu_data.universe = 0;
    }
}