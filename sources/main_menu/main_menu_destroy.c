/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "rpg.h"
#include "menus/menu.h"

void main_menu_destroy(engine_t *engine)
{
    menu_data_t *data = &engine->menu_data;

    if (data->menu)
        (data->menu->funcs.destroy)(data->menu);
    if (data->input)
        free(data->input);
    screen_destroy(&data->screen);
}