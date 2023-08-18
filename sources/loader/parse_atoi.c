/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

int parse_atoi(char **str)
{
    int res = 0;

    while (**str && '0' <= **str && **str <= '9') {
        res = res * 10 + **str - '0';
        (*str)++;
    }
    return (res);
}