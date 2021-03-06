/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "level_gen.h"
#include "floor.h"
#include "tiles_id.h"
#include "entities/entity.h"
#include "entities/slime.h"
#include "entities/zombie.h"
#include "random.h"
#include <stdio.h>

void floor_try_spawn(floor_t *self, int tries)
{
    entity_t *new = 0;
    int type;

    for (int i = 0; i < tries; i++) {
        type = random_int(2);
        if (type == 0)
            new = slime_create(1);
        if (type == 1)
            new = zombie_create(1);
        if ((*new->funcs.start_pos)(new, self)) {
            floor_add(self, new);
        } else {
            (*new->funcs.destroy)(new);
        }
    }
}