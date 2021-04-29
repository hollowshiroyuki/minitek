/*** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdbool.h>

#ifndef RPG_H_
#define RPG_H_

// Put all typedefs on top so we can use any type anywhere.
typedef struct engine_s engine_t;
typedef struct scene_s scene_t;
typedef struct asset_store_s asset_store_t;
typedef struct menu_data_s menu_data_t;
typedef struct game_data_s game_data_t;
typedef struct universe_s universe_t;
typedef enum engine_states_e engine_states_t;

#include "screen.h"

enum engine_states_e
{
    EN_UNKNOWN,
    EN_RUN,
    EN_STOP,
    EN_ERR
};

struct asset_store_s
{
    sfTexture *gui;
    sfTexture *entities;
    sfTexture *items;
    sfTexture *tiles;
};

struct menu_data_s
{
    bool init;
    sfSprite *logo;
};

struct game_data_s
{
    universe_t *universe;
    screen_t screen;
};

struct scene_s
{
    void (*init)(engine_t *engine);
    void (*update)(engine_t *engine);
    void (*event)(engine_t *engine, sfEvent *event);
    void (*draw)(engine_t *engine, sfRenderWindow *window);
    void (*destroy)(engine_t *engine);
};

struct engine_s
{
    int argc;
    char **argv;
    char **envp;
    engine_states_t state;
    asset_store_t assets;
    int active_scene;
    scene_t scenes[5];
    menu_data_t menu_data;
    game_data_t game_data;
    sfRenderWindow *window;
    long tick_count;
    int ticks;
    int fps;
    sfClock *tick_clk;
    sfClock *second_clk;
    sfView *view;
    sfEvent event;
    int ret;
};

/* Engine */
bool engine_usage(engine_t *engine);
void engine_start(engine_t *engine);
void engine_init(engine_t *engine);
void engine_draw(engine_t *engine);
void engine_update(engine_t *engine);
void engine_events(engine_t *engine);
void engine_destroy(engine_t *engine);
void engine_internal_events(engine_t *engine);
void engine_internal_resized(engine_t *engine);

/* Assets Manager */
void asset_manager_init(engine_t *engine);
void asset_manager_destroy(engine_t *engine);

/* Window */
void window_init(engine_t *engine);
void window_destroy(engine_t *engine);

/* View */
sfView *view_ratio(sfView *view, int width, int height);

/* Scene Menu */
void menu_init(engine_t *engine);
void menu_update(engine_t *engine);
void menu_event(engine_t *engine, sfEvent *event);
void menu_draw(engine_t *engine, sfRenderWindow *window);
void menu_destroy(engine_t *engine);

#endif /* RPG_H_ */