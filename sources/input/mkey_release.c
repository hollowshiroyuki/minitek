/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "input.h"

void mkey_release(mkey_t *key)
{
    int code = key->code;
    int id = key->id;

    memset(key, 0, sizeof(mkey_t));
    key->code = code;
    key->id = id;
}