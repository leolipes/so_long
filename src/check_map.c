/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:57:44 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/09 22:36:25 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_rectangular(t_game *game)
{
	int	y;
	int	width;

	width = ft_strlen(game->map.layout[0]);
	y = 1;
	while(y < game->map.height)
	{
		if(ft_strlen(game->map.layout[y]) != width)
		{
			printf("the map is not rectangular!\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	x;//coluna
	int	y;//linha
	int	player;
	int	collect;
	int	exit;

	x = 0;
	y = 0;
	player = 0;
	collect = 0;
	exit = 0;
	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			if(game->map.layout[y][x] == PLAYER)
				player = 1;
			if(game->map.layout[y][x] == COLLECT)
				collect = 1;
			if(game->map.layout[y][x] == EXIT)
				exit = 1;
			if(game->map.layout[y][x] != PLAYER && \
				game->map.layout[y][x] != COLLECT && \
				game->map.layout[y][x] != EXIT && \
				game->map.layout[y][x] != WALL && \
				game->map.layout[y][x] != FLOOR)
			{
				printf("the map has invalid elements!\n");
				return(0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if(player == 0 || collect == 0 || exit == 0)
	{
		printf("Missing some map element!\n");
		return (0);
	}
	return (1);
}

int	check_is_surrounded(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while(y < game->map.height)
	{
		if(game->map.layout[y][0] != WALL || game->map.layout[y][game->map.width - 1] != WALL)
		{
			printf("the map is not surrounded!\n");
			return (0);
		}
		y++;
	}
	while(x < game->map.width)
	{
		if(game->map.layout[0][x] != WALL || game->map.layout[game->map.height - 1][x] != WALL)
		{
			printf("the map is not surrounded!\n");
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if(check_is_rectangular(game) == 0)
		return (0);
	if(check_elements(game) == 0)
		return (0);
	if(check_is_surrounded(game) == 0)
		return (0);
}
