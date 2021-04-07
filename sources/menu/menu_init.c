/*
** EPITECH PROJECT, 2021
** main
** File description:
** hey. real programmers use vim
*/

#include "rpg.h"
#include "index_gui.h"

static void init_logo(engine_t *engine, menu_data_t *data)
{
    sfVector2f size = sfView_getSize(engine->view);
    sfIntRect rect = gui_tex_index[GUI_TEX_LOGO];
    sfVector2f pos = (sfVector2f){(size.x / 2) - rect.width / 2, 32};

    data->logo = sfSprite_create();
    sfSprite_setTexture(data->logo, engine->assets.gui, sfFalse);
    sfSprite_setTextureRect(data->logo, rect);
    sfSprite_setPosition(data->logo, pos);
}

void menu_init(engine_t *engine)
{
    menu_data_t *data = &engine->menu_data;

    init_logo(engine, data);
    data->init = true;
}
