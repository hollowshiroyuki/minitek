/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "consts.h"

void entities_add_all(entity_t **dest, entity_t **src)
{
    int i = 0;

    while (*dest)
        i++;
    for (int j = 0; j < entities_per_tile && src[j]; j++) {
        dest[i + j] = src[j];
    }
}