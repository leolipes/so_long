/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:21 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/11 20:29:53 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.layout[y])
	{
		free(game->map.layout[y]);
		y++;
	}
	free(game->map.layout);
}

void	free_imgs(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->map.collect.img);
	mlx_destroy_image(game->vars.mlx, game->map.exit.img);
	mlx_destroy_image(game->vars.mlx, game->map.floor.img);
	mlx_destroy_image(game->vars.mlx, game->map.open_exit.img);
	mlx_destroy_image(game->vars.mlx, game->map.wall.img);
	mlx_destroy_image(game->vars.mlx, game->player.sprite[0].img);
	mlx_destroy_image(game->vars.mlx, game->player.sprite[1].img);
	mlx_destroy_image(game->vars.mlx, game->player.sprite[2].img);
	mlx_destroy_image(game->vars.mlx, game->player.sprite[3].img);
}

int	close_game(t_game *game)
{
	free_map(game);
	free_imgs(game);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_loop_end(game->vars.mlx);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(0);
}
