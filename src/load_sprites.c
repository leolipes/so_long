/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:54:31 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 19:47:40 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites_player(t_game *game)
{
	game->player.sprite[0].img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/player/up.xpm", &game->player.sprite[0].width, \
		&game->player.sprite[0].height);
	game->player.sprite[1].img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/player/left.xpm", &game->player.sprite[1].width, \
		&game->player.sprite[1].height);
	game->player.sprite[2].img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/player/right.xpm", &game->player.sprite[2].width, \
		&game->player.sprite[2].height);
	game->player.sprite[3].img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/player/down.xpm", &game->player.sprite[3].width, \
		&game->player.sprite[3].height);
}

void	load_sprites_map(t_game *game)
{
	game->map.floor.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/map/floor.xpm", &game->map.floor.width, \
		&game->map.floor.height);
	game->map.wall.img = mlx_xpm_file_to_image(game->vars.mlx, \
		"./assets/sprites/map/wall.xpm", &game->map.wall.width, \
			&game->map.wall.height);
}

void	load_sprites(t_game *game)
{
	load_sprites_map(game);
	load_sprites_player(game);
}
