/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "input.h"

void *key_init(mkey_t *self, int key)
{
    mkey_t empty = {0};

    if (!self)
        return;
    *self = empty;
    self->code = key;
}