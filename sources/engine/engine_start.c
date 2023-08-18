/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/System.h>
#include <stdio.h>
#include "rpg.h"
#include "hsy.h"

void engine_tick(engine_t *engine)
{
    engine->ticks++;
    engine_events(engine);
    engine_update(engine);
}

void print_time(engine_t *engine)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(engine->second_clk)) > 1) {
        hsy_putnbr(engine->ticks);
        hsy_putstr(" ticks, ");
        hsy_putnbr(engine->fps);
        hsy_putstr(" fps\n");
        engine->ticks = 0;
        engine->fps = 0;
        sfClock_restart(engine->second_clk);
    }
}

void engine_start(engine_t *engine)
{
    int to_process = 0;
    int elapsed = 0;
    sfUint64 msPerTick = 1000000 / 60;

    while (engine->state == EN_RUN && sfRenderWindow_isOpen(engine->window)) {
        elapsed = sfTime_asMicroseconds(sfClock_restart(engine->tick_clk));
        to_process += elapsed / msPerTick;
        while (to_process >= 1) {
            engine_tick(engine);
            to_process -= 1;
        }
        sfSleep((sfTime){2000});
        engine->fps++;
        engine_draw(engine);
        print_time(engine);
    }
    engine_destroy(engine);
}