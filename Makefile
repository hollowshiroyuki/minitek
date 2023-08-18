
########################
### RPG MAKEFILE     ###
########################

########################
### OPTIONS          ###
########################

TARGET_NAME	=	my_rpg
SOURCE_DIR	=	sources
OBJECT_DIR	=	objects
LIBRARY_DIR	=	lib
HEADER_DIR	=	include

vpath %.c $(SOURCE_DIR)

########################
### COMPILER OPTIONS ###
########################

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror \
		-I$(HEADER_DIR) \
		-Wno-unused-variable \
		-Wno-unused-parameter \
		-Wno-deprecated-declarations \
		-Wno-incompatible-pointer-types \
		-g3 \
		$(C_FLAGS_INPUT)

LFLAGS	=	-L$(LIBRARY_DIR) -lhsy \
		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm \
		$(L_FLAGS_INPUT)

########################
### SOURCES FILES    ###
########################

# Pour gérer les dossiers imbriqués dans les sources faire ceci :
# Créer une règle au dessus de ce commentaire contenant les fichiers.
# ex: WINDOW_FILES : window_create.c
# Ajouter une entrée dans SOURCE_FILES comme ceci :
# $(addprefix <nomdudossier>/, $(<NOMDELAREGLE>))

WINDOW_FILES	=	window_init.c \
					window_destroy.c

VIEW_FILES	=	view_ratio.c

ASSET_MAN_FILES	=	asset_manager_destroy.c \
					asset_manager_init.c

MAIN_MENU_FILES	=	main_menu_update.c \
				main_menu_destroy.c \
				main_menu_draw.c \
				main_menu_event.c \
				main_menu_init.c

RANDOM_FILES	=	random_float.c \
					random_int.c \
					randomize_seed.c

LEVEL_GEN_TOP_FILES	=	level_gen_create_top_map.c \
						level_gen_create_and_validate_top_map.c \
						top_map_generate_island.c \
						top_map_generate_sand.c \
						top_map_generate_trees.c \
						top_map_generate_cactus.c \
						top_map_generate_flowers.c

LEVEL_GEN_UNDERGROUND_FILES	=	level_gen_create_underground_map.c \
								level_gen_create_and_validate_underground_map.c \
								underground_map_generate_cave.c \
								underground_map_generate_ores.c

LEVEL_GEN_FILES	=	level_gen_create.c \
					level_gen_sample.c \
					level_gen_set_sample.c \
					level_gen_destroy.c \
					$(addprefix level_gen_create_top_map/, $(LEVEL_GEN_TOP_FILES)) \
					$(addprefix level_gen_create_underground_map/, $(LEVEL_GEN_UNDERGROUND_FILES))

ENGINE_FILES	=	engine_init.c \
					engine_usage.c \
					engine_draw.c \
					engine_start.c \
					engine_update.c \
					engine_events.c \
					engine_destroy.c \
					engine_internal_events.c \
					engine_internal_resized.c

SLIME_FILES	=	slime_create.c \
				slime_funcs.c \
				slime_draw.c

ZOMBIE_FILES	=	zombie_funcs.c

PLAYER_FILES	=	player_create.c \
					player_draw.c \
					player_funcs.c \
					player_tick.c \
					player_find_start_pos.c \
					player_hurt_tile.c \
					player_do_hurt.c \
					player_can_swim.c

MOB_FILES	=	mob_funcs.c \
				mob_tick.c \
				mob_hurt.c \
				mob_do_hurt.c \
				mob_is_swimming.c \
				mob_hurt_tile.c \
				mob_move.c \
				mob_find_start_pos.c \
				$(addprefix slime/, $(SLIME_FILES)) \
				$(addprefix zombie/, $(ZOMBIE_FILES)) \
				$(addprefix player/, $(PLAYER_FILES))

ENTITIES_FILES	=	entity_is_blockable_by.c \
					entity_can_swim.c \
					entity_create.c \
					entity_destroy.c \
					entity_draw.c \
					entity_hurt.c \
					entity_init.c \
					entity_interact.c \
					entity_move_axis.c \
					entity_move.c \
					entity_tick.c \
					entity_touch_item.c \
					entity_touched_by.c \
					entity_use.c \
					entity_instance_of.c \
					entity_funcs.c \
					entity_intersects.c \
					entity_funcs_combine.c \
					entities_funcs.c \
					entities_add.c \
					entities_add_all.c \
					entities_count.c \
					entities_remove.c \
					entity_hurt_tile.c \
					entity_blocks.c \
					entity_find_start_pos.c \
					$(addprefix mob/, $(MOB_FILES))

DIRT_FILES	=	dirt.c \
				dirt_render.c

HOLE_FILES	= hole.c

STAIRUP_FILES	=	stair_up.c

STAIRDOWN_FILES	=	stair_down.c

WATER_FILES	=	water.c \
				water_render.c \
				water_may_pass.c

FLOOR_FILES	=	floor_get_tile.c \
				floor_set_tile.c \
				floor_create.c \
				floor_tick.c \
				floor_draw_background.c \
				floor_destroy.c \
				floor_add.c \
				floor_try_spawn.c \
				floor_insert_entity.c \
				floor_get_entities.c \
				floor_entities_row_clear.c \
				floor_sort_and_draw.c \
				floor_draw_entities.c \
				floor_remove_entity.c

SAND_FILES	=	sand.c \
				sand_render.c

CACTUS_FILES	=	cactus.c \
					cactus_render.c \
					cactus_bump.c \
					cactus_may_pass.c

GRASS_FILES	=	grass.c \
				grass_render.c

TILES_FILES	=	tiles.c \
				$(addprefix dirt/, $(DIRT_FILES)) \
				$(addprefix hole/, $(HOLE_FILES)) \
				$(addprefix stair_up/, $(STAIRUP_FILES)) \
				$(addprefix stair_down/, $(STAIRDOWN_FILES)) \
				$(addprefix water/, $(WATER_FILES)) \
				$(addprefix grass/, $(GRASS_FILES)) \
				$(addprefix sand/, $(SAND_FILES)) \
				$(addprefix cactus/, $(CACTUS_FILES))

UNIVERSE_FILES	=	universe_create.c \
					universe_tick.c \
					universe_draw.c \
					universe_destroy.c \
					universe_draw_gui.c

TEXT_FILES	=	text_draw.c

GAME_FILES	=	game_update.c \
				game_draw.c \
				game_init.c \
				game_destroy.c

SCREEN_FILES	=	screen_init.c \
					screen_render_tile.c \
					screen_set_offset.c \
					screen_destroy.c \
					screen_render_entity.c \
					screen_render_gui.c

TITLE_MENU_FILES	=	title_menu.c \
				title_menu_create.c \
				title_menu_tick.c \
				title_menu_draw.c

MENUS_FILES	=	menu.c \
				menu_tick.c \
				menu_draw.c \
				menu_init.c \
				menu_destroy.c \
				$(addprefix title_menu/, $(TITLE_MENU_FILES))

INPUT_FILES	=	input_create.c \
				mkey_init.c \
				input_tick.c \
				mkey_tick.c \
				input_event.c \
				mkey_toggle.c

SOURCES_FILES	=	main.c \
					consts.c \
					$(addprefix engine/, $(ENGINE_FILES)) \
					$(addprefix view/, $(VIEW_FILES)) \
					$(addprefix window/, $(WINDOW_FILES)) \
					$(addprefix asset_manager/, $(ASSET_MAN_FILES)) \
					$(addprefix main_menu/, $(MAIN_MENU_FILES)) \
					$(addprefix random/, $(RANDOM_FILES)) \
					$(addprefix level_gen/, $(LEVEL_GEN_FILES)) \
					$(addprefix entities/, $(ENTITIES_FILES)) \
					$(addprefix tiles/, $(TILES_FILES)) \
					$(addprefix floor/, $(FLOOR_FILES)) \
					$(addprefix universe/, $(UNIVERSE_FILES)) \
					$(addprefix game/, $(GAME_FILES)) \
					$(addprefix screen/, $(SCREEN_FILES)) \
					$(addprefix input/, $(INPUT_FILES)) \
					$(addprefix menus/, $(MENUS_FILES)) \
					$(addprefix text/, $(TEXT_FILES))

LIBRARY		=	libhsy.a

########################
### OBJECT FILES     ###
########################

OBJECTS	=	$(addprefix $(OBJECT_DIR)/,$(patsubst %.c,%.o,$(SOURCES_FILES)))

########################
### RECIPES          ###
########################

.PHONY: all directories re clean fclean

.PRECIOUS: $(OBJECT_DIR)/. $(OBJECT_DIR)%/.

all: directories $(LIBRARY) $(TARGET_NAME)

directories: | $(SOURCE_DIR) $(OBJECT_DIR)

re:	clean all

clean:
	@make --no-print-directory -C $(LIBRARY_DIR) clean
	@rm -rf ./$(OBJECT_DIR)

fclean: clean
	@make --no-print-directory -C $(LIBRARY_DIR) fclean
	@rm -rf ./$(OBJECT_DIR)
	@rm -f ./$(TARGET_NAME)

library: $(LIBRARY)

########################
### FILE GENERATORS  ###
########################

$(TARGET_NAME): $(OBJECTS)
	@$(CC) -o $(TARGET_NAME) $^ $(LFLAGS)
	@echo -e "😺\e[35m -- BUILD SUCCESSFUL --\e[0m"

$(LIBRARY):
	@make -C $(LIBRARY_DIR) --no-print-directory

$(OBJECT_DIR):
	@mkdir -p $@

$(OBJECT_DIR)/.:
	@mkdir -p $@

$(OBJECT_DIR)%/.:
	@mkdir -p $@

$(SOURCE_DIR):
	@echo "🙀\e[31m -- Error: source folder not found !\e[0m"

.SECONDEXPANSION:

########################
### IMPLICITS REDEFS ###
########################

$(OBJECT_DIR)/%.o : %.c | $$(@D)/.
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo -e "😺\e[35m -- $@ successfully compiled --\e[0m"