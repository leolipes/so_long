# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 17:20:26 by lfilipe-          #+#    #+#              #
#    Updated: 2021/12/02 17:32:47 by lfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ./src/demo.c

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx

FLAGS = -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

OBJS = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)