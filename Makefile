# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 01:30:19 by lfilipe-          #+#    #+#              #
#    Updated: 2021/12/09 17:06:26 by lfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCE =	./src/so_long.c \
			./src/game_init.c ./src/load_sprites.c \
			./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			./src/map_gen.c ./src/draw_game.c ./src/map_init.c \
			./src/key_hook.c \
			./src/player_position.c

NAME = so_long

CC = gcc

#CFLAGS = -Wall -Wextra -Werror -Imlx

FLAGS = -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

OBJS = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) -L./libft -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

libft:
	make -C ./libft

.PHONY: libft