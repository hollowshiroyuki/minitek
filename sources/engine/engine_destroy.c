/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "scenes.h"

void engine_destroy(engine_t *engine)
{
    for (int i = 0; i < S_COUNT; i++) {
        if (scenes[i].destroy) {
            (*scenes[i].destroy)(engine);
        }
    }
    sfClock_destroy(engine->tick_clk);
    sfClock_destroy(engine->second_clk);
    window_destroy(engine);
    asset_manager_destroy(engine);
}