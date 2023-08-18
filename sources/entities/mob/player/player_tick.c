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
#include "universe.h"
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

static bool change_level(entity_t *self)
{
    return (false);
}

static void move(entity_t *self)
{
    sfVector2i new_pos = {0};

    new_pos.y -= (self->mob.pla.input->up.down) ? 1 : 0;
    new_pos.y += (self->mob.pla.input->down.down) ? 1 : 0;
    new_pos.x -= (self->mob.pla.input->left.down) ? 1 : 0;
    new_pos.x += (self->mob.pla.input->right.down) ? 1 : 0;
    if (mob_is_swimming(self) && self->mob.tick_time % 60 == 0) {
        if (self->mob.pla.stamina > 0)
            self->mob.pla.stamina--;
        else
            (*self->funcs.hurt)(self, self, 1, self->mob.dir);
    }
    if (self->mob.pla.stamina_delay % 2 == 0)
        (*self->funcs.move)(self, new_pos);
}

void interact(entity_t *self)
{
    input_t *input = self->mob.pla.input;
    menu_t *menu;

    if (input->attack.clicked) {
        if (self->mob.pla.stamina) {
            self->mob.pla.stamina--;
            self->mob.pla.stamina_reload = 0;
            player_attack(self);
        }
    }
    if (input->menu.clicked) {
        if (!player_use(self)) {
            menu = inventory_menu_create(self, "Inventory");
            universe_set_menu(self->mob.pla.universe, menu);
        }
    }
}

void player_tick(entity_t *self)
{
    sfVector2i tile_pos = (sfVector2i){self->pos.x >> 4, self->pos.y >> 4};
    tile_t on_tile = floor_get_tile(self->floor, tile_pos);

    mob_tick(self);
    if (self->mob.pla.invul)
        self->mob.pla.invul--;
    if (change_level(self))
        return;
    stamina_tick(self);
    move(self);
    interact(self);
    if (self->mob.pla.attack_time > 0)
        self->mob.pla.attack_time--;
}