/*
** EPITECH PROJECT, 2020
** hsy_putstr
** File description:
** M-x doctor
*/

#include <unistd.h>
#include "hsy.h"

ssize_t hsy_fd_putstr(int fd, char const *str)
{
    size_t len = hsy_strlen(str);

    return (write(fd, str, len));
}
