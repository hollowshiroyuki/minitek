/*
** EPITECH PROJECT, 2021
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
typedef struct secene_s scene_t;
typedef struct asset_store_s asset_store_t;
typedef enum engine_states_e engine_states_t;

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

struct engine_s
{
    int argc;
    char **argv;
    char **envp;
    engine_states_t state;
    asset_store_t assets;
    sfRenderWindow *window;
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

#endif /* RPG_H_ */