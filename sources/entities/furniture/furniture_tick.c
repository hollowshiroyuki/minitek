/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "tiles_id.h"
#include "entities/furniture.h"

static void move(entity_t *self)
{
    if (self->fur.push_dir == D_UP)
        self->funcs.move(self, (sfVector2i){0, 1});
    if (self->fur.push_dir == D_DOWN)
        self->funcs.move(self, (sfVector2i){0, -1});
    if (self->fur.push_dir == D_RIGHT)
        self->funcs.move(self, (sfVector2i){1, 0});
    if (self->fur.push_dir == D_LEFT)
        self->funcs.move(self, (sfVector2i){-1, 0});
    self->fur.push_dir = -1;
    if (self->fur.push_time > 0)
        self->fur.push_time--;
}

void furniture_tick(entity_t *self)
{
    if (self->fur.player) {
        return;
    }
    move(self);
}