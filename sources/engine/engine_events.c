/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"

void engine_events(engine_t *engine)
{
    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        engine_internal_events(engine);
        if (scenes[engine->active_scene].event) {
            (scenes[engine->active_scene].event)(engine, &engine->event);
        }
    }
}