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

void player_save(entity_t *self, int fd)
{
    inventory_t *inv = self->mob.pla.inventory;

    hsy_fd_putnbr(fd, self->id);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->floor->depth);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->pos.x);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->pos.y);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->mob.id);
    hsy_fd_putstr(fd, ",");
    hsy_fd_putnbr(fd, self->mob.health);
    hsy_fd_putstr(fd, ",");
    if (self->mob.pla.active_item) {
        inventory_add_pos(inv, self->mob.pla.active_item, 1);
        self->mob.pla.active_item = NULL;
    }
    inventory_save(self->mob.pla.inventory, fd);
    hsy_fd_putstr(fd, "\n");
}