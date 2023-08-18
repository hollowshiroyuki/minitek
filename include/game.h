/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.h>

typedef struct engine_s engine_t;

void game_init(engine_t *engine);
void game_update(engine_t *engine);
void game_draw(engine_t *engine, sfRenderWindow *win);
void game_destroy(engine_t *engine);

#endif