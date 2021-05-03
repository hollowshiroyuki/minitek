/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef GUI_H_
#define GUI_H_

#include <SFML/Graphics.h>
#include "screen.h"

void gui_text_draw(char *text, screen_t *screen, sfVector2i pos, sfColor color);
void gui_frame_draw(screen_t *self, char *name, sfVector2i p1, sfVector2i p2);

#endif