/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "input.h"

void engine_events(engine_t *engine)
{
    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        engine_internal_events(engine);
        if (engine->menu_data.input)
            input_event(engine->menu_data.input, &engine->event);
        if (scenes[engine->active_scene].event) {
            (scenes[engine->active_scene].event)(engine, &engine->event);
        }
    }
}