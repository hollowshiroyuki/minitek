/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SFML/Graphics.h>

typedef struct asset_store_s asset_store_t;

enum {
    NO_F,
    HOR_F,
    VER_F
};

typedef struct screen_s
{
    sfVector2i size;
    sfVector2i offset;
    sfRenderWindow *win;
    sfSprite *e_sprite;
    sfSprite *t_sprite;
    sfSprite *i_sprite;
    sfSprite *g_sprite;
} screen_t;

void screen_init(screen_t *self, asset_store_t *assets, sfRenderWindow *win);
void screen_set_offset(screen_t *self, sfVector2i offset);
void screen_destroy(screen_t *self);
void screen_render_tile(screen_t *self, sfVector2i pos, int tile_id, int flip);
void screen_render_entity(screen_t *self, sfVector2i pos, int tile_id, int f);
void screen_render_gui(screen_t *self, sfVector2i pos, int tile_id, int flip);
void screen_sprite_flip(sfSprite *sprite, int m);
void screen_render_item(screen_t *self, sfVector2i pos, int tile_id, int flip);

#endif