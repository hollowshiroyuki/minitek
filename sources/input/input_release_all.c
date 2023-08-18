/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "input.h"

void input_release_all(input_t *input)
{
    for (int i = 0; i < C_COUNT; i++) {
        mkey_release(&input->keys[i]);
    }
}