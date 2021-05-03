/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TOOL_ITEM_H_
#define TOOL_ITEM_H_

#include "item_funcs.h"

typedef struct item_s item_t;

extern const char *level_names[];

extern const item_funcs_t tool_item_funcs;

enum {
    TT_PICK,
    TT_SHOVEL,
    TT_SWORD,
    TT_AXE,
    TT_HOE,
    TT_HEAVY_SWORD
};

typedef struct tool_type_s
{
    int id;
    char *name;
    int tex;
} tool_type_t;

extern const tool_type_t sword_type;
extern const tool_type_t big_sword_type;
extern const tool_type_t pick_type;
extern const tool_type_t axe_type;
extern const tool_type_t shovel_type;
extern const tool_type_t hoe_type;

typedef struct tool_item_s
{
    tool_type_t *type;
    int max_level;
    int level;
    char name[16];
} tool_item_t;

item_t *tool_item_create(tool_type_t *type, int level);
int tool_item_get_tex(item_t *self);
void tool_item_on_take(item_t *self, entity_t *item);
void tool_item_draw_inventory(item_t *self, screen_t *screen, sfVector2i pos);
void tool_item_draw_icon(item_t *self, screen_t *screen, sfVector2i pos);
bool tool_item_interact(item_t *self, entity_t *play, entity_t *item, int dir);
bool tool_item_interact_tile(item_t *self, entity_t *p, entity_t *i, int dir);
bool tool_item_is_depleted(item_t *self);
bool tool_item_can_attack(item_t *self);
int tool_item_attack_bonus(item_t *self, entity_t *e);
char *tool_item_get_name(item_t *self);
bool tool_item_matches(item_t *self, item_t *item);
void tool_item_funcs_combine(item_funcs_t *d, const item_funcs_t *i_f);

#endif