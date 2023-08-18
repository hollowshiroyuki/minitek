
########################
### LIB_HSY MAKEFILE ###
########################

########################
### OPTIONS          ###
########################

TARGET_NAME	=	libhsy.a
SOURCE_DIR	=	sources
OBJECT_DIR	=	objects
HEADER_DIR	=	include

vpath %.c $(SOURCE_DIR)

########################
### COMPILER OPTIONS ###
########################

CC	=	gcc
AR	=	ar
CFLAGS	=	-W -Wall -Wextra -Werror \
		-I$(HEADER_DIR) \
		-Wno-unused-variable \
		-Wno-self-assign \
		-Wno-unused-parameter \
		$(C_FLAGS_INPUT)

########################
### SOURCES FILES    ###
########################

SOURCES_FILES	=	hsy_compute_power_rec.c \
			hsy_compute_square_root.c \
			hsy_find_prime_sup.c \
			hsy_getnbr.c \
			hsy_is_prime.c \
			hsy_isneg.c \
			hsy_putnbr.c \
			hsy_putchar.c \
			hsy_putstr.c \
			hsy_revstr.c \
			hsy_sort_int_array.c \
			hsy_str_isalpha.c \
			hsy_str_islower.c \
			hsy_str_isnum.c \
			hsy_str_isprintable.c \
			hsy_str_isupper.c \
			hsy_str_to_word_array.c \
			hsy_strcapitalize.c \
			hsy_strcat.c \
			hsy_strcmp.c \
			hsy_strcpy.c \
			hsy_strdup.c \
			hsy_strlen.c \
			hsy_strlowcase.c \
			hsy_strncat.c \
			hsy_strncmp.c \
			hsy_strncpy.c \
			hsy_strstr.c \
			hsy_strupcase.c \
			hsy_int_swap.c \
			hsy_fd_putchar.c \
			hsy_fd_putstr.c \
			hsy_fd_putnbr.c \
			hsy_strtol.c \
			hsy_isspace.c \
			hsy_strtoul.c \
			hsy_chrstr.c \
			hsy_atoi.c \
			hsy_fd_printf.c \
			hsy_strndup.c

########################
### OBJECT FILES     ###
########################

OBJECTS	=	$(patsubst %.c, $(OBJECT_DIR)/%.o, $(SOURCES_FILES))

########################
### RECIPES          ###
########################

.PHONY: all directories re clean fclean

all: directories $(TARGET_NAME)

directories: | $(SOURCES_DIR) $(OBJECT_DIR)

re:	clean all

clean:
	@rm -rf ./$(OBJECT_DIR)/*.o

fclean: clean
	@rm -rf ./$(OBJECT_DIR)
	@rm -f ./$(TARGET_NAME)

########################
### FILE GENERATORS  ###
########################

$(TARGET_NAME): $(OBJECTS)
	@$(AR) -rc $(TARGET_NAME) $^
	@cp $(TARGET_NAME) ..
	@cp include/hsy.h ../../include
	@echo -e "😺\e[35m -- LIB_HSY BUILD SUCCESS --\e[0m"

$(OBJECT_DIR):
	@mkdir -p $@

$(SOURCE_DIR):
	@echo "🙀\e[31m -- Error: source folder not found !\e[0m"

########################
### IMPLICITS REDEFS ###
########################

$(OBJECT_DIR)/%.o : %.c
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo -e "😺\e[35m -- $@ successfully compiled --\e[0m"
