/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "input.h"

void mkey_init(mkey_t *key, int code)
{
    mkey_t empty = {0};

    if (!key)
        return;
    *key = empty;
    key->code = code;
}