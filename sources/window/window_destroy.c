/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void window_destroy(engine_t *engine)
{
    if (engine->window)
        sfRenderWindow_destroy(engine->window);
    if (engine->view)
        sfView_destroy(engine->view);
}