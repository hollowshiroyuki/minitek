/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "universe.h"

void main_menu_draw(engine_t *engine, sfRenderWindow *window)
{
    menu_data_t *data = &engine->menu_data;
    game_data_t *game = &engine->game_data;

    title_menu_draw(data->menu, &data->screen);
}
