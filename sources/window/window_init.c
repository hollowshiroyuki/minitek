/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "consts.h"

void window_init(engine_t *engine)
{
    sfVideoMode mode = {render_size.x, render_size.y, 32};
    sfFloatRect rect = {0, 0, mode.width, mode.height};
    sfVector2u win_size = {render_size.x * 3, render_size.y * 3};
    sfUint32 style = sfClose | sfResize;

    engine->window = sfRenderWindow_create(mode, window_name, style, NULL);
    engine->view = sfView_createFromRect(rect);
    sfRenderWindow_setVerticalSyncEnabled(engine->window, sfFalse);
    sfRenderWindow_setFramerateLimit(engine->window, 30);
    sfRenderWindow_setView(engine->window, engine->view);
    sfRenderWindow_setSize(engine->window, win_size);
    view_ratio(engine->view, win_size.x, win_size.y);
    sfRenderWindow_setView(engine->window, engine->view);
}