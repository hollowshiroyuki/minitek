/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void main_menu_destroy(engine_t *engine)
{
    menu_data_t *data = &engine->menu_data;

    if (!data->init)
        return;
    sfSprite_destroy(data->logo);
    data->init = false;
}