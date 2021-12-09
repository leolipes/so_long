/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:13:20 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 20:52:56 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, img->img, \
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

int	draw_map(t_game *game)
{
	int	x;//coluna
	int	y;//linha

	x = 0;
	y = 0;
	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			if (game->map.layout[y][x] == WALL)
				draw_img(game, &game->map.wall, x, y);
			if (game->map.layout[y][x] == FLOOR || game->map.layout[y][x] == \
			PLAYER)
				draw_img(game, &game->map.floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	draw_player(t_game *game)
{
	draw_img(game, &game->player.sprite[game->player.direction], game->player.x, \
		game->player.y);
}

int		draw_game(t_game *game)
{
	draw_map(game);
	draw_player(game);
	return (0);
}
