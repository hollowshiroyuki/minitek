/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef SCENES_H_
#define SCENES_H_

#include "rpg.h"

enum scene_id_e
{
    S_MENU,
    S_COUNT /*This one absolutely need to be the last !*/
};

static const scene_t scenes[] = {
    {
        menu_init,
        menu_update,
        menu_event,
        menu_draw,
        menu_destroy
    }
};

#endif /* SCENES_H_ */