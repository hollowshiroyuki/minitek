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
#include "hsy.h"
#include "entities/workbench.h"

void furniture_save(entity_t *self, int fd)
{
    if (self->fur.id == E_WORKBENCH)
        workbench_save(self, fd);
}