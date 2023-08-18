/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void engine_start(engine_t *engine)
{
    while (engine->state == EN_RUN && sfRenderWindow_isOpen(engine->window)) {
        engine_update(engine);
        engine_draw(engine);
        engine_events(engine);
    }
    engine_destroy(engine);
}