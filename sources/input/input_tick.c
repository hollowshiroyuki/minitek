/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "input.h"

bool input_tick(input_t *input)
{
    for (int i = 0; i < C_COUNT; i++) {
        mkey_tick(&input->keys[i]);
    }
    mkey_tick(&input->tmp);
    if (!input->has_focus) {
        input_release_all(input);
        return (true);
    }
    return (false);
}