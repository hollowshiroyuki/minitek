/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities_id.h"
#include <stdio.h>
#include "random.h"

static bool interact_pos(entity_t *self, item_t *item, int yo, int range)
{
    sfVector2i pos1 = {self->pos.x - 8, self->pos.y + 4 + yo};
    sfVector2i pos2 = {self->pos.x + 8, self->pos.y + range + yo};

    if (self->mob.dir == D_DOWN && player_interact_pos(self, pos1, pos2))
        return (true);
    pos1.y = self->pos.y - range + yo;
    pos2.y = self->pos.y - 4 + yo;
    if (self->mob.dir == D_UP && player_interact_pos(self, pos1, pos2))
        return (true);
    pos1 = (sfVector2i){self->pos.x + 4, self->pos.y - 8 + yo};
    pos2 = (sfVector2i){self->pos.x + range, self->pos.y + 8 + yo};
    if (self->mob.dir == D_RIGHT && player_interact_pos(self, pos1, pos2))
        return (true);
    pos1.x = self->pos.x - range;
    pos2.x = self->pos.x - 4;
    if (self->mob.dir == D_LEFT && player_interact_pos(self, pos1, pos2))
        return (true);
    return (false);
}

static bool use_active_item(entity_t *self, item_t *item, int yo)
{
    int range = 12;
    sfVector2i size = self->floor->size;
    sfVector2i pos = {self->pos.x >> 4, (self->pos.y + yo) >> 4};
    tile_t tile;

    self->mob.pla.attack_time = 10;
    if (interact_pos(self, item, yo, range))
        return (true);
    pos.y = (self->mob.dir == D_DOWN) ? (self->pos.y + range + yo) >> 4 : pos.y;
    pos.y = (self->mob.dir == D_UP) ? (self->pos.y - range + yo) >> 4 : pos.y;
    pos.x = (self->mob.dir == D_LEFT) ? (self->pos.x - range) >> 4 : pos.x;
    pos.x = (self->mob.dir == D_RIGHT) ? (self->pos.x + range) >> 4 : pos.x;
    if (pos.x >= 0 && pos.y >= 0 && pos.x < size.x && pos.y < size.y) {
        tile = floor_get_tile(self->floor, pos);
        if ((item->funcs.interact_tile)(item, tile, pos, self))
            return (true);
        if (tile.interact && (*tile.interact)(tile, self->floor, pos, self))
            return (true);
    }
    return (false);
}

static void attack_entities(entity_t *self, int  yo, int range)
{
    sfVector2i pos1 = {0};
    sfVector2i pos2 = {0};

    if (self->mob.dir == D_DOWN) {
        pos1 = (sfVector2i){self->pos.x - 8, self->pos.y + 4 + yo};
        pos2 = (sfVector2i){self->pos.x + 8, self->pos.y + range + yo};
    }
    if (self->mob.dir == D_UP) {
        pos1 = (sfVector2i){self->pos.x - 8, self->pos.y - range + yo};
        pos2 = (sfVector2i){self->pos.x + 8, self->pos.y + 4 + yo};
    }
    if (self->mob.dir == D_LEFT) {
        pos1 = (sfVector2i){self->pos.x + 4, self->pos.y - 8 + yo};
        pos2 = (sfVector2i){self->pos.x + range, self->pos.y + 8 + yo};
    }
    if (self->mob.dir == D_RIGHT) {
        pos1 = (sfVector2i){self->pos.x - range, self->pos.y - 8 + yo};
        pos2 = (sfVector2i){self->pos.x - 4, self->pos.y + 8 + yo};
    }
    player_hurt_pos(self, pos1, pos2);
}

void attack_tile(entity_t *self, int yo, int radius)
{
    sfVector2i size = self->floor->size;
    sfVector2i p = (sfVector2i){self->pos.x >> 4, (self->pos.y + yo) >> 4};
    tile_t tile;

    p.y = (self->mob.dir == D_DOWN) ? (self->pos.y + radius + yo) >> 4 : p.y;
    p.y = (self->mob.dir == D_UP) ? (self->pos.y - radius + yo) >> 4 : p.y;
    p.x = (self->mob.dir == D_LEFT) ? (self->pos.x - radius) >> 4 : p.x;
    p.x = (self->mob.dir == D_RIGHT) ? (self->pos.x + radius) >> 4 : p.x;
    if (p.y >= 0 && p.x >= 0 && p.y < size.y && p.x < size.x) {
        tile = floor_get_tile(self->floor, p);
        if (tile.hurt)
            (*tile.hurt)(self->floor, p, self, random_int(3) + 1);
    }
}

void player_attack(entity_t *self)
{
    int yo = -2;
    item_t *active_item = self->mob.pla.active_item;

    self->mob.walk_dist += 8;
    if (active_item) {
        self->mob.pla.attack_time = 10;
        if (use_active_item(self, active_item, yo)) {
            if ((*active_item->funcs.is_depleted)(active_item)) {
                (active_item->funcs.destroy)(active_item);
                self->mob.pla.active_item = 0;
            }
            return;
        }
    }
    if (!active_item || (*active_item->funcs.can_attack)(active_item)) {
        self->mob.pla.attack_time = 5;
        attack_entities(self, yo, 20);
        attack_tile(self, yo, 20);
    }
}