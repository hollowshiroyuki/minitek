/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef TIL_INDEX_H_
#define TIL_INDEX_H_

#include "rpg.h"

typedef enum til_tex_id_e
{
/* Ligne 1 */
    TIL_TEX_TREE_TL,        /* Tree Top Left */
    TIL_TEX_TREE_TR,        /* Tree Top Right */
    TIL_TEX_PART_WATER_1,   /* Water Particle 1 */
    TIL_TEX_PART_WATER_2,   /* Water Particle 2 */
    TIL_TEX_PART_WATER_3,   /* Water Particle 3 */
    TIL_TEX_PART_WATER_4,   /* Water Particle 4 */
    TIL_TEX_CACTUS_TL,      /* Cactus Top Left */
    TIL_TEX_CACTUS_TR,      /* Cactus Top Right */
    TIL_TEX_WOOL_WHI_TL,    /* Wool White Top Left */
    TIL_TEX_WOOL_WHI_TR,
    TIL_TEX_WOOL_RED_TL,
    TIL_TEX_WOOL_RED_TR,
    TIL_TEX_FARMLAND,
    TIL_TEX_WHEAT_1,
    TIL_TEX_WHEAT_2,
    TIL_TEX_WHEAT_3,
    TIL_TEX_WHEAT_4,
    TIL_TEX_WHEAT_5,
    TIL_TEX_WHEAT_6,
    TIL_TEX_STAIR_UP_TL,
    TIL_TEX_STAIR_UP_TR,
    TIL_TEX_STAIR_DOWN_TL,
    TIL_TEX_STAIR_DOWN_TR,
    TIL_TEX_IRON_TL,
    TIL_TEX_IRON_TR,
    TIL_TEX_LAPIS_TL,
    TIL_TEX_LAPIS_TR,
    TIL_TEX_GOLD_TL,
    TIL_TEX_GOLD_TR,
    TIL_TEX_GEM_TL,
    TIL_TEX_GEM_TR,
/* Ligne 2 */
    TIL_TEX_TREE_BL,        /* Tree Bottom Left */
    TIL_TEX_TREE_TR_F,      /* Tree Top Right Forest (when there's 4 adjascent trees) */
    TIL_TEX_PART_LAVA_1,    /* Water Particle 1 */
    TIL_TEX_PART_LAVA_2,    /* Water Particle 2 */
    TIL_TEX_PART_LAVA_3,    /* Water Particle 3 */
    TIL_TEX_PART_LAVA_4,    /* Water Particle 4 */
    TIL_TEX_CACTUS_BL,
    TIL_TEX_CACTUS_BR,
    TIL_TEX_WOOL_WHI_BL,
    TIL_TEX_WOOL_WHI_BR,
    TIL_TEX_WOOL_RED_BL,
    TIL_TEX_WOOL_RED_BR,
    TIL_TEX_CROP,
    TIL_TEX_CARROT_1,
    TIL_TEX_CARROT_2,
    TIL_TEX_CARROT_3,
    TIL_TEX_CARROT_4,
    TIL_TEX_CARROT_5,
    TIL_TEX_CARROT_6,
    TIL_TEX_STAIR_UP_BL,
    TIL_TEX_STAIR_UP_BR,
    TIL_TEX_STAIR_DOWN_BL,
    TIL_TEX_STAIR_DOWN_BR,
    TIL_TEX_IRON_BL,
    TIL_TEX_IRON_BR,
    TIL_TEX_LAPIS_BL,
    TIL_TEX_LAPIS_BR,
    TIL_TEX_GOLD_BL,
    TIL_TEX_GOLD_BR,
    TIL_TEX_GEM_BL,
    TIL_TEX_GEM_BR,
/* Ligne 3 */
    TIL_TEX_TREE_TL_F,
    TIL_TEX_CRYSTAL_TL,
    TIL_TEX_CRYSTAL_TR,
    TIL_TEX_WOOL_BLU_TL,
    TIL_TEX_WOOL_BLU_TR,
    TIL_TEX_WOOL_GRE_TL,
    TIL_TEX_WOOL_GRE_TR,
    TIL_TEX_DIRT_1_TL,
    TIL_TEX_DIRT_1_TR,
    TIL_TEX_DIRT_2_TL,
    TIL_TEX_DIRT_2_TR,
/* Ligne 4 */
    TIL_TEX_TREE_BR,
    TIL_TEX_CRYSTAL_BL,
    TIL_TEX_CRYSTAL_BR,
    TIL_TEX_WOOL_BLU_BL,
    TIL_TEX_WOOL_BLU_BR,
    TIL_TEX_WOOL_GRE_BL,
    TIL_TEX_WOOL_GRE_BR,
    TIL_TEX_DIRT_1_BL,
    TIL_TEX_DIRT_1_BR,
    TIL_TEX_DIRT_2_BL,
    TIL_TEX_DIRT_2_BR,
/*  Ligne 5 */
    TIL_TEX_WOOL_YEL_TL,
    TIL_TEX_WOOL_YEL_TR,
    TIL_TEX_WOOL_BLK_TL,
    TIL_TEX_WOOL_BLK_TR,
    TIL_TEX_DIRT_3_TL,
    TIL_TEX_DIRT_3_TR,
    TIL_TEX_DIRT_4_TL,
    TIL_TEX_DIRT_4_TR,
/* Ligne 6 */
    TIL_TEX_WOOL_YEL_BL,
    TIL_TEX_WOOL_YEL_BR,
    TIL_TEX_WOOL_BLK_BL,
    TIL_TEX_WOOL_BLK_BR,
    TIL_TEX_DIRT_3_BL,
    TIL_TEX_DIRT_3_BR,
    TIL_TEX_DIRT_4_BL,
    TIL_TEX_DIRT_4_BR,
/* Ligne 7 */
    TIL_TEX_GRASS_TL,
    TIL_TEX_GRASS_TM,
    TIL_TEX_GRASS_TR,
    TIL_TEX_PART_GRASS_TL,
    TIL_TEX_PART_GRASS_TR,
    TIL_TEX_SAND_TL,
    TIL_TEX_SAND_TM,
    TIL_TEX_SAND_TR,
    TIL_TEX_PART_SAND_TL,
    TIL_TEX_PART_SAND_TR,
    TIL_TEX_WATER_TL,
    TIL_TEX_WATER_TM,
    TIL_TEX_WATER_TR,
    TIL_TEX_STONE_TL,
    TIL_TEX_STONE_TM,
    TIL_TEX_STONE_TR,
    TIL_TEX_PART_STONE_TL,
    TIL_TEX_PART_STONE_TR,
    TIL_TEX_HOLE_TL,
    TIL_TEX_HOLE_TM,
    TIL_TEX_HOLE_TR,
    TIL_TEX_PART_HOLE_TL,
    TIL_TEX_PART_HOLE_TR,
/* Ligne 8 */
    TIL_TEX_GRASS_ML,
    TIL_TEX_GRASS_MM,
    TIL_TEX_GRASS_MR,
    TIL_TEX_PART_GRASS_BL,
    TIL_TEX_PART_GRASS_BR,
    TIL_TEX_SAND_ML,
    TIL_TEX_SAND_MM,
    TIL_TEX_SAND_MR,
    TIL_TEX_PART_SAND_BL,
    TIL_TEX_PART_SAND_BR,
    TIL_TEX_WATER_ML,
    TIL_TEX_WATER_MM,
    TIL_TEX_WATER_MR,
    TIL_TEX_STONE_ML,
    TIL_TEX_STONE_MM,
    TIL_TEX_STONE_MR,
    TIL_TEX_PART_STONE_BL,
    TIL_TEX_PART_STONE_BR,
    TIL_TEX_HOLE_ML,
    TIL_TEX_HOLE_MM,
    TIL_TEX_HOLE_MR,
    TIL_TEX_PART_HOLE_BL,
    TIL_TEX_PART_HOLE_BR,
/* Ligne 9 */
    TIL_TEX_GRASS_BL,
    TIL_TEX_GRASS_BM,
    TIL_TEX_GRASS_BR,
    TIL_TEX_FLOWER,
    TIL_TEX_SAND_BL,
    TIL_TEX_SAND_BM,
    TIL_TEX_SAND_BR,
    TIL_TEX_FOOTPRINT,
    TIL_TEX_WATER_BL,
    TIL_TEX_WATER_BM,
    TIL_TEX_WATER_BR,
    TIL_TEX_STONE_BL,
    TIL_TEX_STONE_BM,
    TIL_TEX_STONE_BR,
    TIL_TEX_ROCK_TL,
    TIL_TEX_ROCK_TR,
    TIL_TEX_HOLE_BL,
    TIL_TEX_HOLE_BM,
    TIL_TEX_HOLE_BR,
/* Ligne 10 */
    TIL_TEX_LAVA_TL,
    TIL_TEX_LAVA_TM,
    TIL_TEX_LAVA_TR,
    TIL_TEX_STONE_ALT_TL,
    TIL_TEX_STONE_ALT_TM,
    TIL_TEX_STONE_ALT_TR,
    TIL_TEX_ROCK_BL,
    TIL_TEX_ROCK_BR,
/* Ligne 11 */
    TIL_TEX_LAVA_ML,
    TIL_TEX_LAVA_MM,
    TIL_TEX_LAVA_MR,
    TIL_TEX_STONE_ALT_ML,
    TIL_TEX_STONE_ALT_MM,
    TIL_TEX_STONE_ALT_MR,
    TIL_TEX_ROCK_ALT_TL,
    TIL_TEX_ROCK_ALT_TR,
/* Ligne 12 */
    TIL_TEX_LAVA_BL,
    TIL_TEX_LAVA_BM,
    TIL_TEX_LAVA_BR,
    TIL_TEX_STONE_ALT_BL,
    TIL_TEX_STONE_ALT_BM,
    TIL_TEX_STONE_ALT_BR,
    TIL_TEX_ROCK_ALT_BL,
    TIL_TEX_ROCK_ALT_BR,
/* Bois, Pierre, Obsi  Ligne 1 */
    TIL_TEX_WOOD_WALL_TL,
    TIL_TEX_WOOD_WALL_TM,
    TIL_TEX_WOOD_WALL_TR,
    TIL_TEX_WOOD_WALL_DETAIL_TL,
    TIL_TEX_WOOD_WALL_DETAIL_TR,
    TIL_TEX_WOOD_GROUND_TL,
    TIL_TEX_WOOD_GROUND_TR,
    TIL_TEX_STONE_WALL_TL,
    TIL_TEX_STONE_WALL_TM,
    TIL_TEX_STONE_WALL_TR,
    TIL_TEX_STONE_WALL_DETAIL_TL,
    TIL_TEX_STONE_WALL_DETAIL_TR,
    TIL_TEX_STONE_GROUND_TL,
    TIL_TEX_STONE_GROUND_TR,
    TIL_TEX_OBSI_WALL_TL,
    TIL_TEX_OBSI_WALL_TM,
    TIL_TEX_OBSI_WALL_TR,
    TIL_TEX_OBSI_WALL_DETAIL_TL,
    TIL_TEX_OBSI_WALL_DETAIL_TR,
    TIL_TEX_OBSI_GROUND_TL,
    TIL_TEX_OBSI_GROUND_TR,
/* Bois, Pierre, Obsi  Ligne 2*/
    TIL_TEX_WOOD_WALL_ML,
    TIL_TEX_WOOD_WALL_MM,
    TIL_TEX_WOOD_WALL_MR,
    TIL_TEX_WOOD_WALL_DETAIL_BL,
    TIL_TEX_WOOD_WALL_DETAIL_BR,
    TIL_TEX_WOOD_GROUND_BL,
    TIL_TEX_WOOD_GROUND_BR,
    TIL_TEX_STONE_WALL_ML,
    TIL_TEX_STONE_WALL_MM,
    TIL_TEX_STONE_WALL_MR,
    TIL_TEX_STONE_WALL_DETAIL_BL,
    TIL_TEX_STONE_WALL_DETAIL_BR,
    TIL_TEX_STONE_GROUND_BL,
    TIL_TEX_STONE_GROUND_BR,
    TIL_TEX_OBSI_WALL_ML,
    TIL_TEX_OBSI_WALL_MM,
    TIL_TEX_OBSI_WALL_MR,
    TIL_TEX_OBSI_WALL_DETAIL_BL,
    TIL_TEX_OBSI_WALL_DETAIL_BR,
    TIL_TEX_OBSI_GROUND_BL,
    TIL_TEX_OBSI_GROUND_BR,
/* Bois, Pierre, Obsi, Ligne 3 */
    TIL_TEX_WOOD_WALL_BL,
    TIL_TEX_WOOD_WALL_BM,
    TIL_TEX_WOOD_WALL_BR,
    TIL_TEX_WOOD_DOOR_OPEN_TL,
    TIL_TEX_WOOD_DOOR_OPEN_TR,
    TIL_TEX_WOOD_DOOR_CLOSE_TL,
    TIL_TEX_WOOD_DOOR_CLOSE_TR,
    TIL_TEX_STONE_WALL_BL,
    TIL_TEX_STONE_WALL_BM,
    TIL_TEX_STONE_WALL_BR,
    TIL_TEX_STONE_DOOR_OPEN_TL,
    TIL_TEX_STONE_DOOR_OPEN_TR,
    TIL_TEX_STONE_DOOR_CLOSE_TL,
    TIL_TEX_STONE_DOOR_CLOSE_TR,
    TIL_TEX_OBSI_WALL_BL,
    TIL_TEX_OBSI_WALL_BM,
    TIL_TEX_OBSI_WALL_BR,
    TIL_TEX_OBSI_DOOR_OPEN_TL,
    TIL_TEX_OBSI_DOOR_OPEN_TR,
    TIL_TEX_OBSI_DOOR_CLOSE_TL,
    TIL_TEX_OBSI_DOOR_CLOSE_TR,
    /* Bois, Pierre, Obsi, Ligne 4 */
    TIL_TEX_WOOD_DOOR_OPEN_BL,
    TIL_TEX_WOOD_DOOR_OPEN_BR,
    TIL_TEX_WOOD_DOOR_CLOSE_BL,
    TIL_TEX_WOOD_DOOR_CLOSE_BR,
    TIL_TEX_STONE_DOOR_OPEN_BL,
    TIL_TEX_STONE_DOOR_OPEN_BR,
    TIL_TEX_STONE_DOOR_CLOSE_BL,
    TIL_TEX_STONE_DOOR_CLOSE_BR,
    TIL_TEX_OBSI_DOOR_OPEN_BL,
    TIL_TEX_OBSI_DOOR_OPEN_BR,
    TIL_TEX_OBSI_DOOR_CLOSE_BL,
    TIL_TEX_OBSI_DOOR_CLOSE_BR
} til_tex_id_t;

const sfIntRect til_tex_index[] = {
/* Ligne 1 */
    {0, 0, 8, 8},
    {8, 0, 8, 8},
    {16, 0, 8, 8},
    {24, 0, 8, 8},
    {32, 0, 8, 8},
    {40, 0, 8, 8},
    {48, 0, 8, 8},
    {56, 0, 8, 8},
    {64, 0, 8, 8},
    {72, 0, 8, 8},
    {80, 0, 8, 8},
    {88, 0, 8, 8},
    {96, 0, 8, 8},
    {104, 0, 8, 8},
    {112, 0, 8, 8},
    {120, 0, 8, 8},
    {128, 0, 8, 8},
    {136, 0, 8, 8},
    {144, 0, 8, 8},
    {152, 0, 8, 8},
    {160, 0, 8, 8},
    {168, 0, 8, 8},
    {176, 0, 8, 8},
    /*{184, 0, 8, 8},*/ //Hole between Stairs and Ores.
    {192, 0, 8, 8},
    {200, 0, 8, 8},
    {208, 0, 8, 8},
    {216, 0, 8, 8},
    {224, 0, 8, 8},
    {232, 0, 8, 8},
    {240, 0, 8, 8},
    {248, 0, 8, 8},
/* Ligne 2 */
    {0, 8, 8, 8},
    {8, 8, 8, 8},
    {16, 8, 8, 8},
    {24, 8, 8, 8},
    {32, 8, 8, 8},
    {40, 8, 8, 8},
    {48, 8, 8, 8},
    {56, 8, 8, 8},
    {64, 8, 8, 8},
    {72, 8, 8, 8},
    {80, 8, 8, 8},
    {88, 8, 8, 8},
    {96, 8, 8, 8},
    {104, 8, 8, 8},
    {112, 8, 8, 8},
    {120, 8, 8, 8},
    {128, 8, 8, 8},
    {136, 8, 8, 8},
    {144, 8, 8, 8},
    {152, 8, 8, 8},
    {160, 8, 8, 8},
    {168, 8, 8, 8},
    {176, 8, 8, 8},
    /*{184, 8, 8, 8},*/ // Hole between Stairs and Ores
    {192, 8, 8, 8},
    {200, 8, 8, 8},
    {208, 8, 8, 8},
    {216, 8, 8, 8},
    {224, 8, 8, 8},
    {232, 8, 8, 8},
    {240, 8, 8, 8},
    {248, 8, 8, 8},
/* Ligne 3 */
    {8, 16, 8, 8},
    /*{16, 16, 8, 8},
    {24, 16, 8, 8},
    {32, 16, 8, 8},
    {40, 16, 8, 8},*/
    {48, 16, 8, 8},
    {56, 16, 8, 8},
    {64, 16, 8, 8},
    {72, 16, 8, 8},
    {80, 16, 8, 8},
    {88, 16, 8, 8},
    {96, 16, 8, 8},
    {104, 16, 8, 8},
    {112, 16, 8, 8},
    {120, 16, 8, 8},
/* Ligne 4 */
    {8, 24, 8, 8},
    /*{16, 24, 8, 8},
    {24, 24, 8, 8},
    {32, 24, 8, 8},
    {40, 24, 8, 8},*/
    {48, 24, 8, 8},
    {56, 24, 8, 8},
    {64, 24, 8, 8},
    {72, 24, 8, 8},
    {80, 24, 8, 8},
    {88, 24, 8, 8},
    {96, 24, 8, 8},
    {104, 24, 8, 8},
    {112, 24, 8, 8},
    {120, 24, 8, 8},
/* Ligne 5 */
    {64, 32, 8, 8},
    {72, 32, 8, 8},
    {80, 32, 8, 8},
    {88, 32, 8, 8},
    {96, 32, 8, 8},
    {104, 32, 8, 8},
    {112, 32, 8, 8},
    {120, 32, 8, 8},
/* Ligne 6 */
    {64, 40, 8, 8},
    {72, 40, 8, 8},
    {80, 40, 8, 8},
    {88, 40, 8, 8},
    {96, 40, 8, 8},
    {104, 40, 8, 8},
    {112, 40, 8, 8},
    {120, 40, 8, 8},
/* Ligne 7 */
    {0, 48, 8, 8},
    {8, 48, 8, 8},
    {16, 48, 8, 8},
    {24, 48, 8, 8},
    {32, 48, 8, 8},
    /*{40, 48, 8, 8},*/
    {48, 48, 8, 8},
    {56, 48, 8, 8},
    {64, 48, 8, 8},
    {72, 48, 8, 8},
    {80, 48, 8, 8},
    /*{88, 48, 8, 8},*/
    {96, 48, 8, 8},
    {104, 48, 8, 8},
    {112, 48, 8, 8},
    /*{120, 48, 8, 8},
    {128, 48, 8, 8},
    {136, 48, 8, 8},*/
    {144, 48, 8, 8},
    {152, 48, 8, 8},
    {160, 48, 8, 8},
    {168, 48, 8, 8},
    {176, 48, 8, 8},
    /*{184, 48, 8, 8},*/
    {192, 48, 8, 8},
    {200, 48, 8, 8},
    {208, 48, 8, 8},
    {216, 48, 8, 8},
    {224, 48, 8, 8},
/* Ligne 8 */
    {0, 56, 8, 8},
    {8, 56, 8, 8},
    {16, 56, 8, 8},
    {24, 56, 8, 8},
    {32, 56, 8, 8},
    /*{40, 56, 8, 8},*/
    {48, 56, 8, 8},
    {56, 56, 8, 8},
    {64, 56, 8, 8},
    {72, 56, 8, 8},
    {80, 56, 8, 8},
    /*{88, 56, 8, 8},*/
    {96, 56, 8, 8},
    {104, 56, 8, 8},
    {112, 56, 8, 8},
    /*{120, 56, 8, 8},
    {128, 56, 8, 8},
    {136, 56, 8, 8},*/
    {144, 56, 8, 8},
    {152, 56, 8, 8},
    {160, 56, 8, 8},
    {168, 56, 8, 8},
    {176, 56, 8, 8},
    /*{184, 56, 8, 8},*/
    {192, 56, 8, 8},
    {200, 56, 8, 8},
    {208, 56, 8, 8},
    {216, 56, 8, 8},
    {224, 56, 8, 8},
/* Ligne 9 */
    {0, 64, 8, 8},
    {8, 64, 8, 8},
    {16, 64, 8, 8},
    {24, 64, 8, 8},
    /*{32, 64, 8, 8},
    {40, 64, 8, 8},*/
    {48, 64, 8, 8},
    {56, 64, 8, 8},
    {64, 64, 8, 8},
    {72, 64, 8, 8},
    /*{80, 64, 8, 8},
    {88, 64, 8, 8},*/
    {96, 64, 8, 8},
    {104, 64, 8, 8},
    {112, 64, 8, 8},
    /*{120, 64, 8, 8},
    {128, 64, 8, 8},
    {136, 64, 8, 8},*/
    {144, 64, 8, 8},
    {152, 64, 8, 8},
    {160, 64, 8, 8},
    {168, 64, 8, 8},
    {176, 64, 8, 8},
    /*{184, 64, 8, 8},*/
    {192, 64, 8, 8},
    {200, 64, 8, 8},
    {208, 64, 8, 8},
/* Ligne 10 */
    {96, 72, 8, 8},
    {104, 72, 8, 8},
    {112, 72, 8, 8},
    /*{120, 72, 8, 8},
    {128, 72, 8, 8},
    {136, 72, 8, 8},*/
    {144, 72, 8, 8},
    {152, 72, 8, 8},
    {160, 72, 8, 8},
    {168, 72, 8, 8},
    {176, 72, 8, 8},
/* Ligne 11 */
    {96, 80, 8, 8},
    {104, 80, 8, 8},
    {112, 80, 8, 8},
    /*{120, 80, 8, 8},
    {128, 80, 8, 8},
    {136, 80, 8, 8},*/
    {144, 80, 8, 8},
    {152, 80, 8, 8},
    {160, 80, 8, 8},
    {168, 80, 8, 8},
    {176, 80, 8, 8},
/* Ligne 12  */
    {96, 88, 8, 8},
    {104, 88, 8, 8},
    {112, 88, 8, 8},
    /*{120, 88, 8, 8},
    {128, 88, 8, 8},
    {136, 88, 8, 8},*/
    {144, 88, 8, 8},
    {152, 88, 8, 8},
    {160, 88, 8, 8},
    {168, 88, 8, 8},
    {176, 88, 8, 8},
/* Bois Pierre Obsi Ligne 1 */
    {0, 112, 8, 8},
    {8, 112, 8, 8},
    {16, 112, 8, 8},
    {24, 112, 8, 8},
    {32, 112, 8, 8},
    {40, 112, 8, 8},
    {48, 112, 8, 8},
    /*{56, 112, 8, 8},
    {64, 112, 8, 8},
    {72, 112, 8, 8},*/
    {80, 112, 8, 8},
    {88, 112, 8, 8},
    {96, 112, 8, 8},
    {104, 112, 8, 8},
    {112, 112, 8, 8},
    {120, 112, 8, 8},
    {128, 112, 8, 8},
    /*{136, 112, 8, 8},
    {144, 112, 8, 8},
    {152, 112, 8, 8},*/
    {160, 112, 8, 8},
    {168, 112, 8, 8},
    {176, 112, 8, 8},
    {184, 112, 8, 8},
    {192, 112, 8, 8},
    {200, 112, 8, 8},
    {208, 112, 8, 8},
/* Bois Pierre Obsi Ligne 2 */
    {0, 120, 8, 8},
    {8, 120, 8, 8},
    {16, 120, 8, 8},
    {24, 120, 8, 8},
    {32, 120, 8, 8},
    {40, 120, 8, 8},
    {48, 120, 8, 8},
    /*{56, 120, 8, 8},
    {64, 120, 8, 8},
    {72, 120, 8, 8},*/
    {80, 120, 8, 8},
    {88, 120, 8, 8},
    {96, 120, 8, 8},
    {104, 120, 8, 8},
    {112, 120, 8, 8},
    {120, 120, 8, 8},
    {128, 120, 8, 8},
    /*{136, 120, 8, 8},
    {144, 120, 8, 8},
    {152, 120, 8, 8},*/
    {160, 120, 8, 8},
    {168, 120, 8, 8},
    {176, 120, 8, 8},
    {184, 120, 8, 8},
    {192, 120, 8, 8},
    {200, 120, 8, 8},
    {208, 120, 8, 8},
/* Bois Pierre Obsi Ligne 3 */
    {0, 128, 8, 8},
    {8, 128, 8, 8},
    {16, 128, 8, 8},
    {24, 128, 8, 8},
    {32, 128, 8, 8},
    {40, 128, 8, 8},
    {48, 128, 8, 8},
    /*{56, 128, 8, 8},
    {64, 128, 8, 8},
    {72, 128, 8, 8},*/
    {80, 128, 8, 8},
    {88, 128, 8, 8},
    {96, 128, 8, 8},
    {104, 128, 8, 8},
    {112, 128, 8, 8},
    {120, 128, 8, 8},
    {128, 128, 8, 8},
    /*{136, 128, 8, 8},
    {144, 128, 8, 8},
    {152, 128, 8, 8},*/
    {160, 128, 8, 8},
    {168, 128, 8, 8},
    {176, 128, 8, 8},
    {184, 128, 8, 8},
    {192, 128, 8, 8},
    {200, 128, 8, 8},
    {208, 128, 8, 8},
/* Bois Pierre Obsi Ligne 4 */
    {24, 136, 8, 8},
    {32, 136, 8, 8},
    {40, 136, 8, 8},
    {48, 136, 8, 8},
    {104, 136, 8, 8},
    {112, 136, 8, 8},
    {120, 136, 8, 8},
    {128, 136, 8, 8},
    {184, 136, 8, 8},
    {192, 136, 8, 8},
    {200, 136, 8, 8},
    {208, 136, 8, 8}
};

#endif
