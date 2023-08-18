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
    int code;
    bool down;
    bool clicked;
    int presses;
    int absorbs;
} mkey_t;

void mkey_toggle(mkey_t *self, bool pressed);
void mkey_tick(mkey_t *self);
void mkey_init(mkey_t *key, int code);
void mkey_release(mkey_t *key);

enum {
    C_UP,
    C_DOWN,
    C_LEFT,
    C_RIGHT,
    C_MENU,
    C_ATTACK,
    C_ACCEPT,
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
            mkey_t menu;
            mkey_t attack;
            mkey_t accept;
        };
        mkey_t keys[C_COUNT];
    };
    bool has_focus;
} input_t;

input_t *input_create(void);
void input_toggle(input_t *self, sfEvent *event, bool pressed);
void input_release_all(input_t *self);
bool input_tick(input_t *self);
void input_event(input_t *input, sfEvent *event);


#endif