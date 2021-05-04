/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"

static bool use_pos(entity_t *self, int yo)
{
    sfVector2i pos1 = {self->pos.x - 8, self->pos.y + 4 + yo};
    sfVector2i pos2 = {self->pos.x + 8, self->pos.y + 12 + yo};

    if (self->mob.dir == D_DOWN && player_use_pos(self, pos1, pos2))
        return (true);
    pos1.y = self->pos.y - 12 + yo;
    pos2.y = self->pos.y - 4 + yo;
    if (self->mob.dir == D_UP && player_use_pos(self, pos1, pos2))
        return (true);
    pos1 = (sfVector2i){self->pos.x + 4, self->pos.y - 8 + yo};
    pos2 = (sfVector2i){self->pos.x + 12, self->pos.y + 8 + yo};
    if (self->mob.dir == D_RIGHT && player_use_pos(self, pos1, pos2))
        return (true);
    pos1.x = self->pos.x - 12;
    pos2.x = self->pos.x - 4;
    if (self->mob.dir == D_LEFT && player_use_pos(self, pos1, pos2))
        return (true);
    return (false);
}

bool player_use(entity_t *self)
{
    int yo = -2;
    int r = 12;
    sfVector2i size = self->floor->size;
    sfVector2i pos = {self->pos.x >> 4, (self->pos.y + yo) >> 4};
    tile_t tile;

    if (use_pos(self, yo))
        return (true);
    pos.y = (self->mob.dir == D_DOWN) ? (self->pos.y + r + yo) >> 4 : pos.y;
    pos.y = (self->mob.dir == D_UP) ? (self->pos.y - r + yo) >> 4 : pos.y;
    pos.x = (self->mob.dir == D_LEFT) ? (self->pos.x - r) >> 4 : pos.x;
    pos.x = (self->mob.dir == D_RIGHT) ? (self->pos.x + r) >> 4 : pos.x;
    if (pos.x >= 0 && pos.y >= 0 && pos.x < size.x && pos.y < size.y) {
        tile = floor_get_tile(self->floor, pos);
        if (tile.use && (*tile.use)(tile, self->floor, pos, self))
            return (true);
    }
    return (false);
}