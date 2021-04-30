/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include "entities/entity.h"
#include "entities/player.h"
#include "entities/mob.h"
#include "screen.h"
#include "tiles_id.h"
#include <stdio.h>

static void stamina_tick(entity_t *self)
{
    player_t *pla = &self->mob.pla;

    if (pla->stamina <= 0 && !pla->stamina_delay && !pla->stamina_reload)
        pla->stamina_delay = 40;
    if (pla->stamina_delay)
        pla->stamina_delay--;
    if (pla->stamina_delay == 0) {
        pla->stamina_reload++;
        if (mob_is_swimming(self))
            pla->stamina_reload = 0;
        while (pla->stamina_reload > 10) {
            pla->stamina_reload -= 10;
            if (pla->stamina < pla->max_stamina)
                pla->stamina++;
        }
    }
}

void player_tick(entity_t *self)
{
    sfVector2i tile_pos = (sfVector2i){self->pos.x >> 4, self->pos.y >> 4};
    tile_t on_tile = floor_get_tile(self->floor, tile_pos);
    sfVector2i new_pos = {0};

    mob_tick(self);
    if (self->mob.pla.invul)
        self->mob.pla.invul--;
    //if (on_tile.id == T_STAIRUP || on_tile.id == T_STAIRDOWN)
    //    player_change_floor(self, (on_tile.id == T_STAIRUP) ? 1 : -1);
    stamina_tick(self);
    new_pos.y -= (self->mob.pla.input->up.down) ? 1 : 0;
    new_pos.y += (self->mob.pla.input->down.down) ? 1 : 0;
    new_pos.x -= (self->mob.pla.input->left.down) ? 1 : 0;
    new_pos.x += (self->mob.pla.input->right.down) ? 1 : 0;
    mob_move(self, new_pos);
}