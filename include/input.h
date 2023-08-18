/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef INPUT_H_
#define INPUT_H_

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct key_s
{
    int id;
    int code;
    bool down;
    bool clicked;
    int presses;
    int absorbs;
} mkey_t;

void mkey_toggle(mkey_t *self, bool pressed);
void mkey_tick(mkey_t *self);
void mkey_init(mkey_t *key, int code, int id);
void mkey_release(mkey_t *key);

enum {
    C_UP,
    C_DOWN,
    C_LEFT,
    C_RIGHT,
    C_ATTACK,
    C_MENU,
    C_ACCEPT,
    C_PAUSE,
    C_COUNT
};

typedef struct input_s
{
    union {
        struct {
            mkey_t up;
            mkey_t down;
            mkey_t left;
            mkey_t right;
            mkey_t attack;
            mkey_t menu;
            mkey_t accept;
            mkey_t escape;
        };
        mkey_t keys[C_COUNT];
    };
    mkey_t tmp;
    bool has_focus;
    char *buf;
    int buf_pos;
    int buf_len;
} input_t;

input_t *input_create(void);
void input_toggle(input_t *self, sfEvent *event, bool pressed);
void input_release_all(input_t *self);
bool input_tick(input_t *self);
void input_event(input_t *input, sfEvent *event);


#endif