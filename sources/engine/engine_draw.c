/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"

void engine_draw(engine_t *engine)
{
    sfRenderWindow_clear(engine->window, sfBlack);
    if (scenes[engine->active_scene].draw) {
        (*scenes[engine->active_scene].draw)(engine, engine->window);
    }
    sfRenderWindow_display(engine->window);
}