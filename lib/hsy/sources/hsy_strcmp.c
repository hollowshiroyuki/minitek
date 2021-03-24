/*
** EPITECH PROJECT, 2020
** hsy_strcmp
** File description:
** hello world?
*/

#include "hsy.h"

int hsy_strcmp(char const *s1, char const *s2)
{
    size_t s1_len = hsy_strlen(s1);

    return (hsy_strncmp(s1, s2, s1_len));
}
