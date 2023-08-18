/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "input.h"

input_t *input_create(void)
{
    input_t *new = malloc(sizeof(input_t));

    new->has_focus = true;
    new->tmp = (mkey_t){0};
    mkey_init(&new->up, sfKeyZ, C_UP);
    mkey_init(&new->down, sfKeyS, C_DOWN);
    mkey_init(&new->left, sfKeyQ, C_LEFT);
    mkey_init(&new->right, sfKeyD, C_RIGHT);
    mkey_init(&new->attack, sfKeyA, C_ATTACK);
    mkey_init(&new->menu, sfKeyE, C_MENU);
    mkey_init(&new->accept, sfKeyReturn, C_ACCEPT);
    mkey_init(&new->escape, sfKeyEscape, C_PAUSE);
    return (new);
}