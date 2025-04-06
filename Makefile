# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlimon <tom.limon@>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:38:25 by tomlimon          #+#    #+#              #
#    Updated: 2025/04/06 21:22:41 by tomlimon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Directories
SRC_DIR = ./src
INC_DIR = ./include
MLX_DIR = $(INC_DIR)/minilibx
GNL_DIR = $(INC_DIR)/GNL
OBJ_DIR = ./obj

# Sources
SRCS = $(SRC_DIR)/main/main.c \
       $(SRC_DIR)/utils/error.c $(SRC_DIR)/utils/debug.c \
       $(SRC_DIR)/parsing/verif.c $(SRC_DIR)/parsing/parsing.c $(SRC_DIR)/parsing/verif_map.c \
       $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
       $(SRC_DIR)/graphic/windows.c $(SRC_DIR)/utils/utils.c $(SRC_DIR)/graphic/init_player.c \
	   $(SRC_DIR)/graphic/raycasting.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#macos
#-L./include/minilibx -I./include/minilibx -lmlx -lXext -lX11 -lm -lz

#linux
#-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(MLX_DIR)/libmlx.a
	@echo -e "$(YELLOW)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo -e "$(GREEN)Compilation successful!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/main $(OBJ_DIR)/utils $(OBJ_DIR)/parsing $(OBJ_DIR)/graphic

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	@echo -e "$(YELLOW)Building MinilibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo -e "$(YELLOW)Cleaning object files...$(RESET)"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(YELLOW)Removing executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
