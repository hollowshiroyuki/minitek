
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
					player_can_swim.c \
					player_pay_stamina.c \
					player_destroy.c \
					player_use.c \
					player_use_pos.c \
					player_attack.c \
					player_interact_pos.c \
					player_hurt_pos.c \
					player_get_attack_damage.c

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

WORKBENCH_FILES	=	workbench_create.c \
					workbench_use.c \
					workbench_funcs.c

FURNITURE_FILES	=	furniture_funcs.c \
					furniture_init.c \
					furniture_tick.c \
					furniture_draw.c \
					furniture_blocks.c \
					furniture_touched_by.c \
					furniture_take.c \
					furniture_destroy.c \
					$(addprefix workbench/, $(WORKBENCH_FILES))

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
					entity_heal.c \
					$(addprefix mob/, $(MOB_FILES)) \
					$(addprefix furniture/, $(FURNITURE_FILES))

DIRT_FILES	=	dirt.c \
				dirt_render.c

HOLE_FILES	= hole.c

TREE_FILES	=	tree.c \
				tree_render.c \
				tree_may_pass.c

STAIRUP_FILES	=	stair_up.c \
					stair_up_render.c

STAIRDOWN_FILES	=	stair_down.c \
					stair_down_render.c

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
				floor_remove_entity.c \
				floor_get_data.c

SAND_FILES	=	sand.c \
				sand_render.c

FARMLAND_FILES	=	farmland.c \
					farmland_render.c

CACTUS_FILES	=	cactus.c \
					cactus_render.c \
					cactus_bump.c \
					cactus_may_pass.c

GRASS_FILES	=	grass.c \
				grass_render.c

ROCK_FILES	=	rock.c \
				rock_render.c \
				rock_may_pass.c

FLOWER_FILES	=	flower.c \
					flower_render.c

WHEAT_FILES	=	wheat.c \
				wheat_render.c

CARROT_FILES	=	carrot.c \
					carrot_render.c

ORE_FILES	=	ore.c \
				ore_render.c

TILES_FILES	=	tiles.c \
				$(addprefix dirt/, $(DIRT_FILES)) \
				$(addprefix hole/, $(HOLE_FILES)) \
				$(addprefix stair_up/, $(STAIRUP_FILES)) \
				$(addprefix stair_down/, $(STAIRDOWN_FILES)) \
				$(addprefix water/, $(WATER_FILES)) \
				$(addprefix grass/, $(GRASS_FILES)) \
				$(addprefix sand/, $(SAND_FILES)) \
				$(addprefix cactus/, $(CACTUS_FILES)) \
				$(addprefix rock/, $(ROCK_FILES)) \
				$(addprefix tree/, $(TREE_FILES)) \
				$(addprefix flower/, $(FLOWER_FILES)) \
				$(addprefix farmland/, $(FARMLAND_FILES)) \
				$(addprefix wheat/, $(WHEAT_FILES)) \
				$(addprefix carrot/, $(CARROT_FILES)) \
				$(addprefix ore/, $(ORE_FILES))

UNIVERSE_FILES	=	universe_create.c \
					universe_tick.c \
					universe_draw.c \
					universe_destroy.c \
					universe_draw_gui.c \
					universe_set_menu.c

GUI_FILES	=	gui_text_draw.c \
				gui_frame_draw.c

GAME_FILES	=	game_update.c \
				game_draw.c \
				game_init.c \
				game_destroy.c

SCREEN_FILES	=	screen_init.c \
					screen_render_tile.c \
					screen_set_offset.c \
					screen_destroy.c \
					screen_render_entity.c \
					screen_render_gui.c \
					screen_sprite_flip.c \
					screen_render_item.c

TITLE_MENU_FILES	=	title_menu.c \
					title_menu_create.c \
					title_menu_tick.c \
					title_menu_draw.c

INVENTORY_MENU_FILES	=	inventory_menu_create.c \
							inventory_menu_draw.c \
							inventory_menu_tick.c \
							inventory_menu.c

CRAFTING_MENU_FILES	=	crafting_menu.c \
						crafting_menu_create.c \
						crafting_menu_draw.c \
						crafting_menu_destroy.c \
						crafting_menu_tick.c

MENUS_FILES	=	menu.c \
				menu_tick.c \
				menu_draw.c \
				menu_init.c \
				menu_destroy.c \
				menu_draw_item_list.c \
				$(addprefix title_menu/, $(TITLE_MENU_FILES)) \
				$(addprefix inventory_menu/, $(INVENTORY_MENU_FILES)) \
				$(addprefix crafting_menu/, $(CRAFTING_MENU_FILES))

INPUT_FILES	=	input_create.c \
				mkey_init.c \
				input_tick.c \
				mkey_tick.c \
				input_event.c \
				mkey_toggle.c

TOOL_ITEM_FILES	=	tool_item_create.c \
					tool_item_funcs.c \
					tool_item_attack_bonus.c \
					tool_item_can_attack.c \
					tool_item_draw_icon.c \
					tool_item_draw_inventory.c \
					tool_item_get_name.c \
					tool_item_get_tex.c

RESOURCE_ITEM_FILES	=	resource_item_create.c \
						resource_item_draw_icon.c \
						resource_item_draw_inventory.c \
						resource_item_funcs.c \
						resource_item_get_name.c \
						resource_item_get_tex.c \
						resource_item_interact_tile.c \
						resource_item_is_depleted.c

INVENTORY_FILES	=	inventory_create.c \
					inventory_add.c \
					inventory_add_pos.c \
					inventory_destroy.c \
					inventory_find_resource.c \
					inventory_has_resources.c \
					inventory_remove_resource.c \
					inventory_remove_item.c \
					inventory_count.c

FURNITURE_ITEM_FILES	=	furniture_item_create.c \
							furniture_item_draw_inventory.c \
							furniture_item_draw_icon.c \
							furniture_item_interact_tile.c \
							furniture_item_can_attack.c \
							furniture_item_get_tex.c \
							furniture_item_get_name.c \
							furniture_item_is_depleted.c \
							furniture_item_funcs.c \
							furniture_item_destroy.c

ITEMS_FILES	=	resources.c \
				resource_interact.c \
				food_interact.c \
				plant_interact.c \
				tool_types.c \
				item_get_tex.c \
				item_on_take.c \
				item_draw_inventory.c \
				item_draw_icon.c \
				item_interact.c \
				item_interact_tile.c \
				item_is_depleted.c \
				item_can_attack.c \
				item_attack_bonus.c \
				item_get_name.c \
				item_matches.c \
				item_funcs_combine.c \
				item_funcs.c \
				item_destroy.c \
				item_list_add.c \
				item_list_size.c \
				item_list_remove.c \
				$(addprefix tool_item/, $(TOOL_ITEM_FILES)) \
				$(addprefix resource_item/, $(RESOURCE_ITEM_FILES)) \
				$(addprefix furniture_item/, $(FURNITURE_ITEM_FILES))

TOOL_RECIPE_FILES	=	tool_recipe_create.c \
						tool_recipe_funcs.c

RECIPES_FILES	=	craft_create.c \
					recipe_add_cost.c \
					recipe_add.c \
					workbench_recipes_create.c \
					recipe_funcs_combine.c \
					recipe_funcs.c \
					recipe_destroy.c \
					recipe_deduct_cost.c \
					recipe_check_can_craft.c \
					recipe_craft.c \
					recipe_list_destroy.c \
					craft_destroy.c \
					recipe_init.c \
					recipe_list_delink.c \
					recipe_list_copy.c \
					recipe_list_size.c \
					recipe_list_get.c \
					recipe_list_sort.c \
					$(addprefix tool_recipe/, $(TOOL_RECIPE_FILES))

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
					$(addprefix gui/, $(GUI_FILES)) \
					$(addprefix items/, $(ITEMS_FILES)) \
					$(addprefix inventory/, $(INVENTORY_FILES)) \
					$(addprefix recipes/, $(RECIPES_FILES))

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