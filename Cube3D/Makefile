# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX_DIR := $(LIB_DIR)/mlx_linux

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
$(SRC_DIR)/utils/get_next_line.c \
$(SRC_DIR)/utils/matrix_counter.c \
$(SRC_DIR)/utils/strchr.c \
$(SRC_DIR)/parsing/parser_control.c \
$(SRC_DIR)/parsing/find_ceeling_floor.c \
$(SRC_DIR)/parsing/texture_finder.c \
$(SRC_DIR)/errors/malloc_error.c \


# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft 

# Executable
TARGET := solong
NAME := $(TARGET)

# Conditional compilation based on target
ifeq ($(MAKECMDGOALS),debug)
 CFLAGS += -g
else ifeq ($(MAKECMDGOALS),optimize)
 CFLAGS += -O2
endif

all: libft $(TARGET)

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean: libft_clean 
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean 
	rm -f $(TARGET)

re: fclean all

bonus:: CFLAGS += -D BONUS=1
bonus: re

rebonus: fclean bonus

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LFLAGS)

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re bonus rebonus

