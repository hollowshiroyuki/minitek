/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <SFML/Graphics.h>
#include "gui.h"
#include "menus/menu.h"
#include "entities/entity.h"
#include "items_id.h"
#include "screen.h"
#include "hsy.h"

static void draw_frames(menu_t *self, screen_t *scr)
{
    char *name = self->name ?: "";
    sfVector2i pos_1hr = (sfVector2i){scr->size.x / 8 - 9, 1};
    sfVector2i pos_2hr = (sfVector2i){scr->size.x / 8 - 1, 3};
    sfVector2i pos_1cr = (sfVector2i){scr->size.x / 8 - 9, 5};
    sfVector2i pos_2cr = (sfVector2i){scr->size.x / 8 - 1, 9};

    gui_frame_draw(scr, "Have", pos_1hr, pos_2hr);
    gui_frame_draw(scr, "Cost", pos_1cr, pos_2cr);
    gui_frame_draw(scr, name, (sfVector2i){1, 1}, (sfVector2i){14, 16});
}

static void draw_costs(menu_t *self, screen_t *scr, recipe_t *recipe)
{
    sfVector2i pos = {scr->size.x - 8 * 8, 0};
    int i = -1;
    int req;
    int has;
    char count[3] = {0};
    sfColor color;

    for (item_t *cur = recipe->cost; cur; cur = cur->next) {
        pos.y = (7 + i++) * 8;
        screen_render_item(scr, pos, cur->funcs.get_tex(cur), 0);
        req = (cur->id == I_RESOURCE) ? cur->res.count : 1;
        has = inventory_count(self->craft.player->mob.pla.inventory, cur);
        color = (has < req) ? sfRed : sfWhite;
        has = (has > 99) ? 99 : has;
        gui_num_draw(has, scr, (sfVector2i){pos.x + 1 * 8, pos.y}, color);
        gui_text_draw("/", scr, (sfVector2i){pos.x + 3 * 8, pos.y}, color);
        gui_num_draw(req, scr, (sfVector2i){pos.x + 4 * 8, pos.y}, color);
    }
}

static void draw_result(menu_t *self, screen_t *scr, recipe_t *recipe)
{
    sfVector2i pos = (sfVector2i){scr->size.x - 8 * 8, 2 * 8};
    item_t *result = recipe->result;
    int tex = recipe->result->funcs.get_tex(recipe->result);
    int has = inventory_count(self->craft.player->mob.pla.inventory, result);
    int has_max = (has > 99) ? 99 : has;

    screen_render_item(scr, pos, tex, 0);
    gui_num_draw(has, scr, (sfVector2i){pos.x + 8, 2 * 8}, sfWhite);
}

void crafting_menu_draw(menu_t *self, screen_t *screen)
{
    int select = self->craft.selection;
    recipe_t *selected = recipe_list_get(self->craft.recipes, select);
    item_t *first_item = self->craft.recipes->result;
    int il_dat[5] = {1, 1, 14, 16, self->craft.selection};

    draw_frames(self, screen);
    (self->funcs.draw_item_list)(self, screen, il_dat, first_item);
    if (recipe_list_size(self->craft.recipes)) {
        draw_result(self, screen, selected);
        draw_costs(self, screen, selected);
    }
}