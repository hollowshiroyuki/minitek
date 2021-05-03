/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

bool entity_intersects(entity_t *self, sfVector2i pos1, sfVector2i pos2)
{
    sfVector2i p;
    bool faces[4];

    faces[0] = self->pos.x + self->box.x < pos1.x;
    faces[1] = self->pos.y + self->box.y < pos1.y;
    faces[2] = self->pos.x - self->box.x > pos2.x;
    faces[3] = self->pos.y - self->box.y > pos2.y;
    return (!(faces[0] || faces[1] || faces[2] || faces[3]));
}