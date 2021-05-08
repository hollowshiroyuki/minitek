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
#include "entities_id.h"
#include "entities/zombie.h"
#include "hsy.h"

void mob_save(entity_t *self, int fd)
{
    if (self->mob.id == E_ZOMBIE)
        zombie_save(self, fd);
    if (self->mob.id == E_SLIME)
        slime_save(self, fd);
}