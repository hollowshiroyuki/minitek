/*
** EPITECH PROJECT, 2020
** hsy_put_nbr
** File description:
** vim > emacs
*/

#include "hsy.h"

ssize_t hsy_fd_putnbr(int fd, int i)
{
    ssize_t ret = 0;

    if (i == -2147483648) {
        hsy_fd_putnbr(fd, -214748364);
        hsy_fd_putchar(fd, '8');
        return (11);
    }
    if (i < 0) {
        i *= -1;
        ret += 1;
        hsy_fd_putchar(fd, '-');
    }
    if (i > 9)
        ret += hsy_fd_putnbr(fd, i / 10);
    hsy_fd_putchar(fd, '0' + i % 10);
    return (ret + 1);
}
