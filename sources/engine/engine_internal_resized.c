/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void engine_internal_resized(engine_t *engine)
{
    sfVector2u size = {engine->event.size.width, engine->event.size.height};
    view_ratio(engine->view, size.x, size.y);
    sfRenderWindow_setView(engine->window, engine->view);
}