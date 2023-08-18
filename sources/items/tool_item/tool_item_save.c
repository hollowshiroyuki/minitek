/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/mob.h"
#include "hsy.h"

void tool_item_save(item_t *self, int fd)
{
    hsy_fd_putnbr(fd, self->id);
    hsy_fd_putstr(fd, " ");
    hsy_fd_putnbr(fd, self->tool.type->id);
    hsy_fd_putstr(fd, " ");
    hsy_fd_putnbr(fd, self->tool.level);
}