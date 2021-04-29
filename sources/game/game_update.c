/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "universe.h"

void game_update(engine_t *engine)
{
    universe_tick(engine->game_data.universe);
}