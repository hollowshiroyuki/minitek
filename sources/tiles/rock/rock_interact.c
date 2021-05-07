/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#include <stdlib.h>
#include "tiles/tile.h"
#include "tiles_id.h"

#include "floor.h"
#include "screen.h"
#include "random.h"
#include "tiles/rock.h"
#include "entities/entity.h"
#include "items_id.h"

bool rock_interact(tile_t self, floor_t *floor, sfVector2i pos, entity_t *e)
{
    int tool_level;

    if (e->mob.pla.active_item->id != I_TOOL)
        return (false);
    if (e->mob.pla.active_item->tool.type->id != pick_type.id)
        return (false);
    tool_level = e->mob.pla.active_item->tool.level;
    if (player_pay_stamina(e, 4 - tool_level)) {
        rock_damage(floor, pos, random_int(10) + tool_level * 5 + 10);
        return (true);
    }
    return (false);
}