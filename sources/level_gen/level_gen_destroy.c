/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"

void level_gen_destroy(level_gen_t *lg)
{
    if (!lg)
        return;
    if (lg->values)
        free(lg->values);
    if (lg)
        free(lg);
}