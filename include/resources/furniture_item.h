/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef FURNITURE_ITEM_H_
#define FURNITURE_ITEM_H_


typedef struct item_s item_t;
typedef struct entity_s entity_t;

extern const item_funcs_t furniture_item_funcs;

typedef struct furniture_item_s
{
    entity_t *furniture;
    bool placed;
} furniture_item_t;

item_t *furniture_item_create(entity_t *furniture);
void furniture_item_destroy(item_t *self);
int furniture_item_get_tex(item_t *self);
void furniture_item_on_take(item_t *self, entity_t *item);
void furniture_item_draw_inventory(item_t *self, screen_t *scr, sfVector2i p);
void furniture_item_draw_icon(item_t *self, screen_t *screen, sfVector2i pos);
bool furniture_item_interact(item_t *self, entity_t *p, entity_t *item, int d);
bool furniture_item_interact_tile(item_t *, tile_t, sfVector2i, entity_t *);
bool furniture_item_is_depleted(item_t *self);
bool furniture_item_can_attack(item_t *self);
int furniture_item_attack_bonus(item_t *self, entity_t *e);
char *furniture_item_get_name(item_t *self);
bool furniture_item_matches(item_t *self, item_t *item);
void furniture_item_funcs_combine(item_funcs_t *d, const item_funcs_t *i_f);
void furniture_item_save(item_t *self, int fd);

#endif