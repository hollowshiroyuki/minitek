/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity_funcs.h"
#include "input.h"
#include "screen.h"
#include "floor.h"
#include "inventory.h"

typedef struct mob_s mob_t;
typedef struct entity_s entity_t;
typedef struct universe_s universe_t;

extern const entity_funcs_t player_funcs;

typedef struct player_s
{
    int invul;
    int stamina_delay;
    int stamina_reload;
    int max_stamina;
    int stamina;
    int attack_time;
    int stair_delay;
    universe_t *universe;
    input_t *input;
    inventory_t *inventory;
    item_t *active_item;
    mob_t *mob;
} player_t;

void player_tick(entity_t *self);
entity_t *player_create(universe_t *universe, input_t *input);
void player_draw(entity_t *self, screen_t *screen);
bool player_start_pos(entity_t *self, floor_t *floor);
void player_do_hurt(entity_t *self, int damage, int dir);
void player_hurt_tile(entity_t *self, tile_t tile, sfVector2i pos, int dmg);
bool player_can_swim(entity_t *self);
bool player_pay_stamina(entity_t *self, int cost);
void player_destroy(entity_t *self);
bool player_use(entity_t *self);
bool player_use_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2);
void player_attack(entity_t *self);
bool player_interact_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2);
void player_hurt_pos(entity_t *self, sfVector2i pos1, sfVector2i pos2);
int player_get_attack_damage(entity_t *self, entity_t *entity);
void player_change_floor(entity_t *self, int dir);
void player_touch_item(entity_t *self, entity_t *item);

#endif