/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:13:20 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/12 23:57:55 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, img->img, \
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	draw_block(t_game *game, char block, int x, int y)
{
	if (block == WALL)
		draw_img(game, &game->map.wall, x, y);
	if (block == FLOOR \
		|| block == PLAYER)
		draw_img(game, &game->map.floor, x, y);
	if (block == COLLECT)
		draw_img(game, &game->map.collect, x, y);
	if (block == EXIT)
	{
		if (game->is_open == 0)
			draw_img(game, &game->map.exit, x, y);
		else
			draw_img(game, &game->map.open_exit, x, y);
	}
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			draw_block(game, game->map.layout[y][x], x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	draw_player(t_game *game)
{
	draw_img(game, &game->player.sprite[game->player.direction], \
		game->player.x, game->player.y);
}

int	draw_game(t_game *game)
{
	draw_map(game);
	if (game->is_open == 0)
		draw_player(game);
	return (0);
}
