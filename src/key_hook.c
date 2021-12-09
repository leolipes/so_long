/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:49 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/09 17:14:09 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if(keycode == KEY_W || keycode == KEY_UP)
	{
		if(game->map.layout[game->player.y - 1][game->player.x] != WALL)
		{
			game->player.y--;
			game->player.steps++;
		}
		game->player.direction = PLAYER_UP;
	}
	if(keycode == KEY_A || keycode == KEY_LEFT)
	{
		if(game->map.layout[game->player.y][game->player.x - 1] != WALL)
		{
			game->player.x--;
			game->player.steps++;
		}
		game->player.direction = PLAYER_LEFT;
	}
	if(keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if(game->map.layout[game->player.y][game->player.x + 1] != WALL)
		{
			game->player.x++;
			game->player.steps++;
		}
		game->player.direction = PLAYER_RIGHT;
	}
	if(keycode == KEY_S || keycode == KEY_DOWN)
	{
		if(game->map.layout[game->player.y + 1][game->player.x] != WALL)
		{
			game->player.y++;
			game->player.steps++;
		}
		game->player.direction = PLAYER_DOWN;
	}
	printf("keycode: %d\n", keycode);
	fflush(stdout);
	return (0);
}
