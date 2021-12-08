# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 17:20:26 by lfilipe-          #+#    #+#              #
#    Updated: 2021/12/04 21:39:21 by lfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE =	./src/main.c \
			./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			./src/map/config.c ./src/map/draw.c \
			./src/game/sprites.c

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