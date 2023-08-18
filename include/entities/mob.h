/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef MOB_H_
#define MOB_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "entities/zombie.h"
#include "entities/slime.h"
#include "entities/player.h"

extern const entity_funcs_t mob_funcs;

typedef struct entity_s entity_t;

enum {
    D_DOWN,
    D_UP,
    D_LEFT,
    D_RIGHT
};

typedef struct mob_s
{
    int id;
    int dir;
    int walk_dist;
    sfVector2i knockback;
    int max_health;
    int health;
    int hurt_time;
    int swim_time;
    int tick_time;
    union {
        slime_t sli;
        zombie_t zom;
        player_t pla;
    };
    entity_t *ent;
} mob_t;

void mob_tick(entity_t *self);
void mob_do_hurt(entity_t *self, int damage, int dir);
void mob_hurt(entity_t *self, entity_t *mob, int damage, int dir);
bool mob_is_swimming(entity_t *self);
bool mob_move(entity_t *self, sfVector2i pos);
void mob_hurt_tile(entity_t *self, tile_t tile, sfVector2i pos, int dmg);
bool mob_start_pos(entity_t *self, floor_t *floor);
void mob_save(entity_t *self, int fd);

#endif