#include <SFML/Graphics.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include "consts.h"
#include "level_gen.h"
#include "tiles_id.h"

sfView *view_ratio(sfView *view, int width, int height);

typedef struct data {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfView *view;
    sfRenderWindow *window;
    sfEvent event;
    maps_t map;
    sfClock *timer;
    int stop;
    int level;
    int size;
} data_t;

void demo_resize_map(data_t *data, int new_size)
{
    if (!(new_size && !(new_size & (new_size - 1))))
        warnx("%d is not a power of 2, expect generator breakage.", new_size);
    data->size = new_size;
    data->map.map = realloc(data->map.map, sizeof(int) * new_size * new_size);
    data->map.data = realloc(data->map.data, sizeof(int) * new_size * new_size);
    sfSprite_setTextureRect(data->sprite, (sfIntRect){0, 0, new_size, new_size});
    sfView_reset(data->view, (sfFloatRect){0, 0, new_size, new_size});
    sfRenderWindow_setView(data->window, data->view);
    sfImage_destroy(data->image);
    data->image = sfImage_create(new_size, new_size);
    printf("Map Size : %d x %d.\n", new_size, new_size);
}

int demo_init(data_t *data)
{
    int size = 256;
    sfVideoMode mode = {size, size, 32};
    sfFloatRect rect = {0, 0, mode.width, mode.height};
    sfUint32 style = sfClose | sfResize;

    data->size = size;
    data->window = sfRenderWindow_create(mode, "GEN_DEMO", style, NULL);
    data->view = sfView_createFromRect(rect);
    data->texture = sfTexture_create(sfTexture_getMaximumSize(), sfTexture_getMaximumSize());
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    demo_resize_map(data, size);
    data->timer = sfClock_create();
    printf("Initialization done.\n");
    return data->window && data->view && data->sprite && data->image && data->texture;
}

sfColor demo_get_color(int tile)
{
    switch (tile) {
        case T_WATER: return sfColor_fromRGB(0x00, 0x00, 0x80);
        case T_GRASS: return sfColor_fromRGB(0x20, 0x80, 0x20);
        case T_ROCK: return sfColor_fromRGB(0xa0, 0xa0, 0xa0);
        case T_DIRT: return sfColor_fromRGB(0x60, 0x40, 0x40);
        case T_SAND: return sfColor_fromRGB(0xa0, 0xa0, 0x40);
        case T_LAVA: return sfColor_fromRGB(0xff, 0x20, 0x20);
        case T_TREE: return sfColor_fromRGB(0x00, 0x30, 0x00);
        case T_CACTUS: return sfColor_fromRGB(0x40, 0xa0, 0x40);
        case T_FLOWER: return sfColor_fromRGB(0xca, 0xca, 0xca);
        case T_STAIRDOWN : return sfBlack;
        case T_STAIRUP: return sfBlack;
        default:
            return sfWhite;
    }
}

void demo_draw_window(data_t *data)
{
    for (int y = 0; y < data->size; y++) {
        for (int x = 0; x < data->size; x++) {
            sfImage_setPixel(data->image, x, y, demo_get_color(data->map.map[x + y * data->size]));
        }
    }
    sfTexture_updateFromImage(data->texture, data->image, 0, 0);
    sfRenderWindow_drawSprite(data->window, data->sprite, NULL);
    sfRenderWindow_display(data->window);
    sfRenderWindow_clear(data->window, sfBlack);
}

void demo_generate(data_t *data)
{
    printf("Generation...\n");
    sfClock_restart(data->timer);
    if (data->level == 0)
        level_gen_generate_top_map(&data->map, data->size, data->size);
    else
        level_gen_generate_underground_map(&data->map, data->size, data->size, data->level - 1);
    printf("DONE. Took %dms\n", sfTime_asMilliseconds(sfClock_restart(data->timer)));
    demo_draw_window(data);
}

void demo_set_level(data_t *data, int level)
{
    char *names[] = {"Surface", "Underground"};

    data->level = level;
    printf("Switching to %s (%d)\n", names[!!level], level);
}

void demo_delete(data_t *data)
{
    sfView_destroy(data->view);
    sfRenderWindow_destroy(data->window);
    sfImage_destroy(data->image);
    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
    sfClock_destroy(data->timer);
    free(data->map.data);
    free(data->map.map);
}

void demo_process_event(data_t *data)
{
    sfEvent *e = &data->event;

    if (e->type == sfEvtClosed) {
        data->stop = 1;
        return;
    }
    if (e->type == sfEvtResized) {
        sfVector2u size = {e->size.width, e->size.height};
        view_ratio(data->view, size.x, size.y);
        sfRenderWindow_setView(data->window, data->view);
        demo_draw_window(data);
    }
    if (e->type == sfEvtKeyPressed) {
        if (e->key.code == sfKeyP)
            demo_resize_map(data, data->size << 1);
        if (e->key.code == sfKeyM)
            demo_resize_map(data, data->size >> 1 ?: 1);
        if (e->key.code == sfKeyA)
            demo_set_level(data, 0);
        if (e->key.code == sfKeyZ)
            demo_set_level(data, 1);
        if (e->key.code == sfKeyE)
            demo_set_level(data, 2);
        if (e->key.code == sfKeyR)
            demo_set_level(data, 3);
        if (e->key.code == sfKeyEscape) {
            data->stop = 1;
            return;
        }
        demo_generate(data);
    }
}

int main(int argc, char **argv)
{
    data_t data = {0};

    if (!demo_init(&data))
        err(1, "cpt");
    demo_generate(&data);
    while (!data.stop && sfRenderWindow_isOpen(data.window)) {
        while (sfRenderWindow_pollEvent(data.window, &data.event))
            demo_process_event(&data);
    }
    demo_delete(&data);
    return 0;
}
