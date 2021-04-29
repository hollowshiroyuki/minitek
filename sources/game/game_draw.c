/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"
#include "universe.h"

void game_draw(engine_t *engine, sfRenderWindow *win)
{
    universe_draw(engine->game_data.universe, &engine->game_data.screen);
}