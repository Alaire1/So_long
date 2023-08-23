# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 20:34:34 by akaraban          #+#    #+#              #
#    Updated: 2023/06/14 04:24:33 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

GREEN = "\033[32m"

RESET = "\033[34m"

SRCFILES = 	c_files/check_map_content.c \
			c_files/path_checking.c \
			c_files/path_checking_utils.c \
			c_files/get_next_line.c \
			c_files/color_utils.c \
			c_files/game_utils.c \
			c_files/image.c \
			c_files/main.c \
			c_files/maps.c \
			c_files/moves.c \
			c_files/moves2.c \
			c_files/utils.c \
			c_files/window.c \
			c_files/key_handlers.c

OBJECTS = $(SRCFILES:.c=.o)


MLX_DIR = ./minilibx
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o : %.c 
	@$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)
	@echo $(GREEN)Compiling $<... $(RESET)

all: $(NAME) 

$(NAME): $(OBJECTS)
	@make -C $(MLX_DIR)
	@$(CC) $(OBJECTS) $(MLX_LIB) -o $(NAME)

clean:
	@rm -f $(OBJECTS)
	@make -C $(MLX_DIR) clean
	@echo $(GREEN)Objects removed correctly$(RESET)

fclean: clean
	@rm -f $(NAME)
	@make -C $(MLX_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re
