/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void engine_events(engine_t *engine)
{
    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        engine_internal_events(engine);
    }
    return;
}