/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/furniture.h"
#include "hsy.h"

void workbench_save(entity_t *self, int fd)
{
    hsy_fd_putnbr(fd, self->id);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->floor->depth);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->pos.x);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->pos.y);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, F_WORKBENCH);
    hsy_fd_putstr(fd, "\n");
    hsy_fd_putnbr(1, self->id);
    hsy_fd_putstr(1, ",");
    hsy_fd_putnbr(1, self->floor->depth);
    hsy_fd_putstr(1, ",");
    hsy_fd_putnbr(1, self->pos.x);
    hsy_fd_putstr(1, ",");
    hsy_fd_putnbr(1, self->pos.y);
    hsy_fd_putstr(1, ",");
    hsy_fd_putnbr(1, F_WORKBENCH);
    hsy_fd_putstr(1, "\n");
}