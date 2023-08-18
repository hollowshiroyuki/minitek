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

void game_init(engine_t *engine)
{
    game_data_t *data = &engine->game_data;

    screen_init(&data->screen, &engine->assets, engine->window);
    data->input = input_create();
    data->universe = universe_create((sfVector2i){256, 256}, data->input, 42);
    universe_set_menu(data->universe, title_menu_create());
    for (int i = 0; i < 0; i++)
        inventory_add(data->universe->player->mob.pla.inventory, tool_item_create((tool_type_t *)(&sword_type), 1));
    //for (int i = 0; i < 10; i++)
    //    inventory_add(data->universe->player->mob.pla.inventory, tool_item_create((tool_type_t *)(&sword_type), 3));
}