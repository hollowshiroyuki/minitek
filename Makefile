
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
		-Wno-unused-but-set-variable \
		-Wno-unused-but-set-parameter \
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

VIEW_FILES		=	view_ratio.c

ENGINE_FILES	=	engine_init.c \
					engine_draw.c \
					engine_start.c \
					engine_update.c \
					engine_events.c \
					engine_destroy.c \
					engine_internal_events.c \
					engine_internal_resized.c

SOURCES_FILES	=	main.c \
					$(addprefix engine/, $(ENGINE_FILES)) \
					$(addprefix view/, $(VIEW_FILES)) \
					$(addprefix window/, $(WINDOW_FILES))

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
