/*
** EPITECH PROJECT, 2020
** libhsy [WSL: Ubuntu-20.04]
** File description:
** hsy_atoi
*/

int hsy_atoi(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (int j = i; str[j] != '\0'; ++j) {
        if ('0' <= str[j] && str[j] <= '9')
            res = res * 10 + str[j] - '0';
        else
            return (0);
    }
    return (sign * res);
}