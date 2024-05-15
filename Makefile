# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 18:07:47 by sarajime          #+#    #+#              #
#    Updated: 2024/05/15 17:46:18 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
INCS = -I./src -L./get_libft -lft -L./MLX42 -lmlx42 -lglfw -L"/Users/sarajime/.brew/opt/glfw/lib/"
FLAGS = -Wall -Werror -Wextra -g
MLX42 = ./MLX42
LIBFT = ./get_libft
SRC_DIR = src/

SRC_FILES = main.c end_game.c valid_game.c map_size.c map_utils.c path.c start_game.c \
load_images.c game_moves.c



OBJECTS = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))


all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) -C $(MLX42)
	$(MAKE) -C $(LIBFT)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(INCS)
	
clean:
	rm -rf $(OBJECTS)
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX42)

fclean: clean
	rm -rf $(OBJECTS)
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(MLX42)
	rm -rf $(NAME)

re: fclean all

norm:
	norminette

.PHONY: all fclean clean re norm