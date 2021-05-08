/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "floor.h"
#include "entities/entity.h"
#include "entities_id.h"
#include "hsy.h"
#include "entities/mob.h"
#include "entities/furniture.h"

void floor_save_entities(entity_t *entities, int fd)
{
    for (entity_t *e = entities; e; e = e->next) {
        if (e->id == E_MOB)
            mob_save(e, fd);
        if (e->id == E_FURNITURE)
            furniture_save(e, fd);
        if (e->id == E_ITEM)
            item_entity_save(e, fd);
    }
}

void floor_save(floor_t *self, int fd)
{
    int size = self->size.x * self->size.y;

    for (int i = 0; i < size; i++) {
        hsy_fd_putnbr(fd, self->tiles[i]);
        if (i != size - 1)
            hsy_fd_putstr(fd, ",");
    }
    hsy_fd_putstr(fd, "\n");
    for (int i = 0; i < size; i++) {
        hsy_fd_putnbr(fd, self->data[i]);
        if (i != size - 1)
            hsy_fd_putstr(fd, ",");
    }
    hsy_fd_putstr(fd, "\n");
    floor_save_entities(self->entities, fd);
    hsy_putstr("Floor saved.\n");
}