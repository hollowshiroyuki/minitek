/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef RESOURCE_ITEM_H_
#define RESOURCE_ITEM_H_

#include "item_funcs.h"
#include "resources/resource.h"

typedef struct item_s item_t;

extern const item_funcs_t resource_item_funcs;

typedef struct resource_item_s
{
    resource_t *resource;
    int count;
} resource_item_t;

item_t *resource_item_create(const resource_t *res, int count);
int resource_item_get_tex(item_t *self);
void resource_item_on_take(item_t *self, entity_t *item);
void resource_item_draw_inventory(item_t *self, screen_t *scr, sfVector2i pos);
void resource_item_draw_icon(item_t *self, screen_t *screen, sfVector2i pos);
bool resource_item_interact(item_t *self, entity_t *p, entity_t *item, int dir);
bool resource_item_interact_tile(item_t *, tile_t *, entity_t *, sfVector2i);
bool resource_item_is_depleted(item_t *self);
bool resource_item_can_attack(item_t *self);
int resource_item_attack_bonus(item_t *self, entity_t *e);
char *resource_item_get_name(item_t *self);
bool resource_item_matches(item_t *self, item_t *item);
void resource_item_funcs_combine(item_funcs_t *d, const item_funcs_t *i_f);

#endif