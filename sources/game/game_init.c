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

    screen_init(&data->screen, &engine->assets, engine->window);
    data->input = input_create();
    data->universe = universe_create((sfVector2i){256, 256}, data->input, 69);
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
    inventory_add(data->universe->player->mob.pla.inventory, furniture_item_create(workbench_create()));
    inventory_add(data->universe->player->mob.pla.inventory, resource_item_create((resource_t *)&r_wood, 10));
    inventory_add(data->universe->player->mob.pla.inventory, resource_item_create((resource_t *)&r_stone, 10));
    //universe_set_menu(data->universe, death_menu_create(data->universe->player));
}