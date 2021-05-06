/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "screen.h"
#include "hsy.h"
#include "gui.h"
#include <stdio.h>

char *mitoa(int num, char str[20])
{
    char *dest = str;

    if (num / 10 != 0)
        dest = mitoa(num / 10, str);
    else if (num < 0)
        *dest++ = '-';
    *dest++ = num % 10 + '0';
    *dest = '\0';
    return (dest);
}

void gui_num_draw(int num, screen_t *screen, sfVector2i pos, sfColor color)
{
    char str[20];

    mitoa(num, str);
    gui_text_draw(str, screen, pos, color);
}