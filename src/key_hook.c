/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:49 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/09 19:50:03 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if(keycode == ESC)
		close_game(game);
	if(keycode == KEY_W || keycode == KEY_UP)
	{
		if (game->map.layout[game->player.y - 1][game->player.x] == EXIT)//se for saida
			check_exit(game);//ler o mapa para ver se coletei todos os coletaveis
		if(game->map.layout[game->player.y - 1][game->player.x] != WALL && \
			game->map.layout[game->player.y - 1][game->player.x] != EXIT)
		{
			game->player.y--;
			game->player.steps++;
		}
		game->player.direction = PLAYER_UP;
	}
	if(keycode == KEY_A || keycode == KEY_LEFT)
	{
		if(game->map.layout[game->player.y][game->player.x - 1] == EXIT)
			check_exit(game);
		if(game->map.layout[game->player.y][game->player.x - 1] != WALL && \
			game->map.layout[game->player.y][game->player.x - 1] != EXIT)
		{
			game->player.x--;
			game->player.steps++;
		}
		game->player.direction = PLAYER_LEFT;
	}
	if(keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (game->map.layout[game->player.y][game->player.x + 1] == EXIT)
			check_exit(game);
		if(game->map.layout[game->player.y][game->player.x + 1] != WALL && \
			game->map.layout[game->player.y][game->player.x + 1] != EXIT)
		{
			game->player.x++;
			game->player.steps++;
		}
		game->player.direction = PLAYER_RIGHT;
	}
	if(keycode == KEY_S || keycode == KEY_DOWN)
	{
		if(game->map.layout[game->player.y + 1][game->player.x] == EXIT)
			check_exit(game);
		if(game->map.layout[game->player.y + 1][game->player.x] != WALL && \
			game->map.layout[game->player.y + 1][game->player.x] != EXIT)
		{
			game->player.y++;
			game->player.steps++;
		}
		game->player.direction = PLAYER_DOWN;
	}
	check_collectible(game);
	return (0);
}
