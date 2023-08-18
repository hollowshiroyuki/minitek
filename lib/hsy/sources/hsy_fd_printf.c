/*
** EPITECH PROJECT, 2020
** libhsy [WSL: Ubuntu-20.04]
** File description:
** hsy_fd_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "hsy.h"

int hsy_printf_print(int fd, char const **format, va_list *list)
{
    if (**format == 's')
        hsy_fd_putstr(fd, va_arg(*list, char *));
    if (**format == 'i' || **format == 'd')
        hsy_fd_putnbr(fd, va_arg(*list, long));
    *format += 1;
    return (0);
}

int hsy_fd_printf(int fd, char const *format, ...)
{
    va_list list;
    int ret = 0;

    va_start(list, format);
    while (*format) {
        if (*format == '%') {
            format += 1;
            ret += hsy_printf_print(fd, &format, &list);
        } else {
            ret += write(fd, format, 1);
        }
        format += 1;
    }
    va_end(list);
    return (0);
}