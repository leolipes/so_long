/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:32:51 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/13 00:02:23 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.layout[game->player.y - 1][game->player.x] == EXIT)
		check_exit(game);
	if (game->map.layout[game->player.y - 1][game->player.x] != WALL && \
		game->map.layout[game->player.y - 1][game->player.x] != EXIT)
	{
		game->player.y--;
		game->player.steps++;
		printf("steps: %d\n", game->player.steps);
	}
	game->player.direction = PLAYER_UP;
}

void	move_left(t_game *game)
{
	if (game->map.layout[game->player.y][game->player.x - 1] == EXIT)
		check_exit(game);
	if (game->map.layout[game->player.y][game->player.x - 1] != WALL && \
		game->map.layout[game->player.y][game->player.x - 1] != EXIT)
	{
		game->player.x--;
		game->player.steps++;
		printf("steps: %d\n", game->player.steps);
	}
	game->player.direction = PLAYER_LEFT;
}

void	move_right(t_game *game)
{
	if (game->map.layout[game->player.y][game->player.x + 1] == EXIT)
		check_exit(game);
	if (game->map.layout[game->player.y][game->player.x + 1] != WALL && \
		game->map.layout[game->player.y][game->player.x + 1] != EXIT)
	{
		game->player.x++;
		game->player.steps++;
		printf("steps: %d\n", game->player.steps);
	}
	game->player.direction = PLAYER_RIGHT;
}

void	move_down(t_game *game)
{
	if (game->map.layout[game->player.y + 1][game->player.x] == EXIT)
		check_exit(game);
	if (game->map.layout[game->player.y + 1][game->player.x] != WALL && \
		game->map.layout[game->player.y + 1][game->player.x] != EXIT)
	{
		game->player.y++;
		game->player.steps++;
		printf("steps: %d\n", game->player.steps);
	}
	game->player.direction = PLAYER_DOWN;
}
