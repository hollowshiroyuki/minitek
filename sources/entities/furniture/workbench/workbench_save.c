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
    hsy_fd_putnbr(fd, self->pos.x);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->pos.y);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->fur.id);
    hsy_fd_putstr(fd, "\n");
}