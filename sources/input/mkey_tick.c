/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "input.h"

void mkey_tick(mkey_t *key)
{
    if (key->absorbs < key->presses) {
        key->absorbs++;
        key->clicked = true;
    } else {
        key->clicked = false;
    }
}