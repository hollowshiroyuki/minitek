/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void engine_draw(engine_t *engine)
{
    sfRenderWindow_clear(engine->window, sfBlack);
    sfRenderWindow_display(engine->window);
}