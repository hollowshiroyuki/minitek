/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "input.h"
#include "hsy.h"

const char *autorized = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

static void fixed_keys_2(input_t *input, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft)
            mkey_toggle(&input->keys[C_ATTACK], true);
        if (event->mouseButton.button == sfMouseRight)
            mkey_toggle(&input->keys[C_ACCEPT], true);
    } else if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            mkey_toggle(&input->keys[C_ATTACK], false);
        if (event->mouseButton.button == sfMouseRight)
            mkey_toggle(&input->keys[C_ACCEPT], false);
    }
}

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
    fixed_keys_2(input, event);
}

static void dynamic_keys(input_t *input, sfEvent *event)
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
}

static void text(input_t *input, sfEvent *event)
{
    char typed = (char)event->text.unicode;

    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyBackspace) {
        if (input->buf && input->buf_pos >= 0) {
            input->buf_pos -= (input->buf_pos == 0) ? 0 : 1;
            input->buf[input->buf_pos] = '\0';
            return;
        }
    }
    typed = ('a' <= typed && typed <= 'z') ? typed - ' ' : typed;
    if (event->type == sfEvtTextEntered) {
        if (input->buf && hsy_chrstr(typed, autorized)) {
            if (input->buf_pos < input->buf_len) {
                input->buf[input->buf_pos] = typed;
                input->buf[input->buf_pos + 1] = '\0';
                input->buf_pos++;
            }
        }
    }
}

void input_event(input_t *input, sfEvent *event)
{
    dynamic_keys(input, event);
    fixed_keys(input, event);
    text(input, event);
    if (event->type == sfEvtGainedFocus)
        input->has_focus = true;
    if (event->type == sfEvtLostFocus)
        input->has_focus = false;
}