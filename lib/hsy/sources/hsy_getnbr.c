/*
** EPITECH PROJECT, 2020
** hsy_getnbr
** File description:
** hello world?
*/

#include "hsy.h"

int hsy_getnbr(char const *str)
{
    int res = 0;
    int sign = 0;
    int i = 0;
    int old = 0;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++)
        sign += (str[i] == '-') ? 1 : 0;
    for (i = i; '0' <= str[i] && str[i] <= '9'; i++) {
        if (res == 214748364 && str[i] == '8' && sign % 2 == 1)
            return (-2147483648);
        old = res;
        res = (res * 10) + (str[i] - '0');
        if (!((res >= 0) ^ (old < 0)))
            return (0);
    }
    res *= (sign % 2 == 0) ? 1 : -1;
    return (res);
}
