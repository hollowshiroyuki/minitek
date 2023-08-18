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

void game_init(engine_t *engine)
{
    game_data_t *data = &engine->game_data;

    screen_init(&data->screen, &engine->assets, engine->window);
    data->input = input_create();
    data->universe = universe_create((sfVector2i){256, 256}, data->input, 42);
    universe_set_menu(data->universe, crafting_menu_create(data->universe->craft->workbench, data->universe->player, "Crafting"));
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
}