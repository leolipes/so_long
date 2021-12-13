/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:57:44 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/12 01:51:51 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_rectangular(t_game *game)
{
	int	y;
	int	width;

	width = ft_strlen(game->map.layout[0]);
	y = 1;
	while (y < game->map.height)
	{
		if (ft_strlen(game->map.layout[y]) != width)
		{
			printf("the map is not rectangular!\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_block(char block, int *player, int *collect, int *exit)
{
	if (block == PLAYER)
		*player = 1;
	if (block == COLLECT)
		*collect = 1;
	if (block == EXIT)
		*exit = 1;
	if (block != PLAYER && block != COLLECT && block != EXIT && \
		block != WALL && block != FLOOR)
	{
		printf("the map has invalid elements!\n");
		return (0);
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	x;
	int	y;
	int	elements[3];

	x = 0;
	y = 0;
	ft_bzero(elements, sizeof(int) * 3);
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (check_block(game->map.layout[y][x], &elements[0], \
			&elements[1], &elements[2]) == 0)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (elements[0] == 0 || elements[1] == 0 || elements[2] == 0)
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
	int	is_surrounded;

	y = -1;
	x = -1;
	is_surrounded = 1;
	while (++y < game->map.height)
	{
		if (game->map.layout[y][0] != WALL || \
			game->map.layout[y][game->map.width - 1] != WALL)
			is_surrounded = 0;
	}
	while (++x < game->map.width)
	{
		if (game->map.layout[0][x] != WALL || \
			game->map.layout[game->map.height - 1][x] != WALL)
			is_surrounded = 0;
	}
	if (is_surrounded == 0)
	{
		printf("the map is not surrounded!\n");
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (check_is_rectangular(game) == 0)
	{
		free_map(game);
		return (0);
	}
	if (check_elements(game) == 0)
	{
		free_map(game);
		return (0);
	}
	if (check_is_surrounded(game) == 0)
	{
		free_map(game);
		return (0);
	}
	return (1);
}
