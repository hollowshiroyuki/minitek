/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"

void engine_update(engine_t *engine)
{
    if (scenes[engine->active_scene].update)
        (scenes[engine->active_scene].update)(engine);
}