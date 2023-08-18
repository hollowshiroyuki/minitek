/*
** EPITECH PROJECT, 2020
** hsy_strtoul
** File description:
** epitech > 42
*/

#include "hsy.h"

unsigned int hsy_strtoul(char const *str, char **endptr)
{
    char *keep = (char *)str;
    int mul = 1;
    int numbers = 0;
    unsigned int res = 0;

    while (hsy_isspace(str[0]))
        str += 1;
    if (str[0] == '-' || str[0] == '+') {
        mul = ((str[0] == '-') ? -1 : 1);
        str += 1;
    }
    while (str[0] >= '0' && str[0] <= '9') {
        res *= 10;
        res += str[0] - '0';
        str += 1;
        numbers += 1;
    }
    *endptr = (numbers) ? (char *)str : keep;
    return (mul * res);
}
