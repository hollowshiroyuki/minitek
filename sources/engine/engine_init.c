/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"

void engine_init(engine_t *engine)
{
    window_init(engine);
    asset_manager_init(engine);
    engine->active_scene = 0;
    (*scenes[0].init)(engine);
    engine->state = EN_RUN;
}