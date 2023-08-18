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

    mkey_init(&new->up, sfKeyZ);
    mkey_init(&new->down, sfKeyS);
    mkey_init(&new->left, sfKeyQ);
    mkey_init(&new->right, sfKeyD);
    mkey_init(&new->attack, sfKeyA);
    mkey_init(&new->menu, sfKeyE);
    mkey_init(&new->accept, sfKeyReturn);
    return (new);
}