/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "input.h"

void mkey_toggle(mkey_t *key, bool pressed)
{
    if (pressed != key->down)
        key->down = pressed;
    if (pressed)
        key->presses++;
}