/*
** EPITECH PROJECT, 2020
** hsy_putstr
** File description:
** M-x doctor
*/

#include "hsy.h"

ssize_t hsy_putstr(char const *str)
{
    return (hsy_fd_putstr(1, str));
}
