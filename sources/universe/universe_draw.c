/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "universe.h"
#include "screen.h"
#include "floor.h"
#include <stdio.h>

static sfVector2i calc_scroll(screen_t *screen, sfVector2i f_size)
{
    sfVector2i scroll = {0};
    int max_pos = 0;

    scroll.x = 0 - screen->size.x / 2;
    scroll.y = 0 - (screen->size.y - 8) / 2;
    scroll.x = (scroll.x < 16) ? (16) : (scroll.x);
    scroll.y = (scroll.y < 16) ? (16) : (scroll.y);
    max_pos = f_size.x * 16 - screen->size.x - 16;
    scroll.x = (scroll.x > max_pos) ? (max_pos) : (scroll.x);
    max_pos = f_size.y * 16 - screen->size.y - 16;
    scroll.y = (scroll.y > max_pos) ? (max_pos) : (scroll.y);
    return (scroll);
}

void universe_draw(universe_t *self, screen_t *screen)
{
    sfVector2i scroll = calc_scroll(screen, self->active_floor->size);

    floor_draw_background(self->active_floor, scroll, screen);
}