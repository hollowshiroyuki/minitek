/*
** EPITECH PROJECT, 2020
** hsy_isspace
** File description:
** xkcd.com/378
*/

#include "hsy.h"

int hsy_isspace(char c)
{
    if (c == ' ')
        return (1);
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}
