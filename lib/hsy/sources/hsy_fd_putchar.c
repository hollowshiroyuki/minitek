/*
** EPITECH PROJECT, 2020
** hsy_putchar
** File description:
** man man
*/

#include <unistd.h>
#include "hsy.h"

void hsy_fd_putchar(int fd, char c)
{
    write(fd, &c, 1);
}
