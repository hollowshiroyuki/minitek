/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void main_menu_draw(engine_t *engine, sfRenderWindow *window)
{
    menu_data_t *data = &engine->menu_data;

    sfRenderWindow_drawSprite(window, data->logo, NULL);
}
