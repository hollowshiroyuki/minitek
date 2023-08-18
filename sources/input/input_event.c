/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "input.h"

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
}