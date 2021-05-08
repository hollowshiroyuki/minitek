/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <string.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "menus/title_menu.h"
#include "universe.h"
#include "hsy.h"
#include "level_gen.h"
#include "tiles_id.h"
#include "random.h"

void set_pixel(sfUint8 *pixels, char r, char g, char b)
{
    pixels[0] = r;
    pixels[1] = g;
    pixels[2] = b;
}

static void paint_texture(sfUint8 *pixels, int *map, sfVector2i size)
{
    int i;

    memset(pixels, 0xFF, sizeof(sfUint8) * size.x * size.y * 4);
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            i = x + y * size.x;
            if (map[i] == T_WATER)
                set_pixel(&pixels[i*4], 0x00, 0x00, 0x80);
            if (map[i] == T_GRASS)
                set_pixel(&pixels[i*4], 0x20, 0x80, 0x20);
            if (map[i] == T_ROCK)
                set_pixel(&pixels[i*4], 0xa0, 0xa0, 0xa0);
            if (map[i] == T_SAND)
                set_pixel(&pixels[i*4], 0xa0, 0xa0, 0x40);
            if (map[i] == T_TREE)
                set_pixel(&pixels[i*4], 0x00, 0x30, 0x00);
        }
    }
}

static sfTexture *generate_background(sfVector2i size)
{
    sfUint8 *pixels = malloc(sizeof(sfUint8) * size.x * size.y * 4);
    sfTexture *texture = sfTexture_create(size.x, size.y);
    maps_t maps;

    randomize_seed();
    maps = level_gen_create_and_validate_top_map(size.x, size.y);
    paint_texture(pixels, maps.map, size);
    sfTexture_updateFromPixels(texture, pixels, size.x, size.y, 0, 0);
    free(maps.data);
    free(maps.map);
    free(pixels);
    return (texture);
}

menu_t *title_menu_create(menu_data_t *data)
{
    menu_t *new = malloc(sizeof(menu_t));

    memset(new, 0, sizeof(menu_t));
    new->name = hsy_strdup("");
    new->title.data = data;
    new->title.background = sfSprite_create();
    new->title.texture = generate_background((sfVector2i){256, 256});
    sfSprite_setTexture(new->title.background, new->title.texture, false);
    new->funcs = title_menu_funcs;
    return (new);
}