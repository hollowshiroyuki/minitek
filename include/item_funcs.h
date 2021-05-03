/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef ITEM_FUNCS_H_
#define ITEM_FUNCS_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "screen.h"

typedef struct item_s item_t;
typedef struct entity_s entity_t;
typedef struct tile_s tile_t;

typedef struct item_funcs_s
{
    int (*get_tex)(item_t *self);
    void (*on_take)(item_t *self, entity_t *item);
    void (*draw_inventory)(item_t *self, screen_t *screen, sfVector2i pos);
    void (*draw_icon)(item_t *self, screen_t *screen, sfVector2i pos);
    bool (*interact)(item_t *self, entity_t *player, entity_t *mob, int dir);
    bool (*interact_tile)(item_t *s, tile_t t, sfVector2i pos, entity_t *p);
    bool (*is_depleted)(item_t *self);
    bool (*can_attack)(item_t *self);
    int (*attack_bonus)(item_t *self, entity_t *e);
    char *(*get_name)(item_t *self);
    bool (*matches)(item_t *self, item_t *item);
    void (*destroy)(item_t *self);
} item_funcs_t;

int item_get_tex(item_t *self);
void item_on_take(item_t *self, entity_t *item);
void item_draw_inventory(item_t *self, screen_t *screen, sfVector2i pos);
bool item_interact(item_t *self, entity_t *play, entity_t *item, int dir);
bool item_interact_tile(item_t *self, tile_t tile, sfVector2i pos, entity_t *);
bool item_is_depleted(item_t *self);
bool item_can_attack(item_t *self);
int item_attack_bonus(item_t *self, entity_t *e);
char *item_get_name(item_t *self);
bool item_matches(item_t *self, item_t *item);
void item_funcs_combine(item_funcs_t *d, const item_funcs_t *i_f);
void item_destroy(item_t *self);

extern const item_funcs_t item_funcs;

#endif