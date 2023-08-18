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

void inventory_save(inventory_t *inventory, int fd)
{
    hsy_fd_putstr(fd, "I|");
    hsy_fd_putnbr(fd, inventory->capacity);
    if (inventory->items)
        hsy_fd_putstr(fd, "|");
    for (item_t *i = inventory->items; i; i = i->next) {
        item_save(i, fd);
        if (i->next)
            hsy_fd_putstr(fd, "|");
    }
}