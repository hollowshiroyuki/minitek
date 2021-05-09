/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "universe.h"
#include "level_gen.h"
#include "floor.h"
#include "hsy.h"
#include "random.h"
#include "consts.h"
#include "entities_id.h"

void player_init(entity_t *e, universe_t *universe, input_t *input)
{
    e->id = E_MOB;
    e->mob.ent = e;
    e->mob.id = MB_PLAYER;
    e->mob.max_health = 10;
    e->mob.pla.max_stamina = 10;
    e->mob.pla.mob = &e->mob;
    e->mob.pla.stamina = 10;
    e->mob.pla.universe = universe;
    e->mob.pla.input = input;
    //entity_funcs_combine(e->funcs, &player_funcs, &mob_funcs);
}

static void floor_init(floor_t *floor, int i)
{
    sfVector2i size = map_size;
    int ept = entities_per_tile;

    floor->size = size;
    floor->depth = i;
    floor->monster_density = 16;
    floor->entities_in_tiles = malloc(sizeof(entity_t **) * size.x * size.y);
    for (int i = 0; i < size.x * size.y; i++) {
        floor->entities_in_tiles[i] = malloc(sizeof(entity_t *) * (ept + 1));
        memset(floor->entities_in_tiles[i], 0, sizeof(entity_t *) * (ept + 1));
    }
    floor->entities_row = malloc(sizeof(entity_t *) * (ept * size.x + 1));
    memset(floor->entities_row, 0, sizeof(entity_t *) * (ept * size.x + 1));
}

void universe_kickstart(universe_t *self, input_t *input)
{
    sfVector2i pos;

    hsy_putstr("Starting the universe...\n");
    self->input = input;
    self->active_floor = self->floors[(long)self->player->floor];
    printf("Setting floor to %i\n", self->player->floor);
    self->player->floor = self->active_floor;
    self->craft = craft_create();
    for (int i = 0; i < 15 && self->floors[i]; i++) {
        floor_init(self->floors[i], i);
        for (entity_t *e = self->floors[i]->entities; e; e = e->next) {
            pos = (sfVector2i){e->pos.x >> 4, e->pos.y >> 4};
            e->floor = self->floors[i];
            floor_insert_entity(self->floors[i], pos, e);
        }
    }
    player_init(self->player, self, input);
    floor_add(self->active_floor, self->player);
    self->running = true;
}