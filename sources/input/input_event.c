/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "input.h"

static void fixed_keys(input_t *input, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyUp)
            mkey_toggle(&input->keys[C_UP], true);
        if (event->key.code == sfKeyDown)
            mkey_toggle(&input->keys[C_DOWN], true);
        if (event->key.code == sfKeyLeft)
            mkey_toggle(&input->keys[C_LEFT], true);
        if (event->key.code == sfKeyRight)
            mkey_toggle(&input->keys[C_RIGHT], true);
    } else if (event->type == sfEvtKeyReleased) {
        if (event->key.code == sfKeyUp)
            mkey_toggle(&input->keys[C_UP], false);
        if (event->key.code == sfKeyDown)
            mkey_toggle(&input->keys[C_DOWN], false);
        if (event->key.code == sfKeyLeft)
            mkey_toggle(&input->keys[C_LEFT], false);
        if (event->key.code == sfKeyRight)
            mkey_toggle(&input->keys[C_RIGHT], false);
    }
}

void input_event(input_t *input, sfEvent *event)
{
    for (int i = 0; i < C_COUNT; i++) {
        if (event->key.code == input->keys[i].code) {
            if (event->type == sfEvtKeyPressed) {
                mkey_toggle(&input->keys[i], true);
            }
            if (event->type == sfEvtKeyReleased) {
                mkey_toggle(&input->keys[i], false);
            }
        }
    }
    if (event->type == sfEvtKeyPressed) {
        mkey_init(&input->tmp, event->key.code, 0);
        mkey_toggle(&input->tmp, true);
    }
    if (event->type == sfEvtKeyReleased)
        mkey_toggle(&input->tmp, false);
    fixed_keys(input, event);
    if (event->type == sfEvtGainedFocus)
        input->has_focus = true;
    if (event->type == sfEvtLostFocus)
        input->has_focus = false;
}