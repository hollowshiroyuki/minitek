/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"

void engine_internal_events(engine_t *engine)
{
    if (engine->event.type == sfEvtClosed)
        engine->state = EN_STOP;
    if (engine->event.type == sfEvtResized)
        engine_internal_resized(engine);
}