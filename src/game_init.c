/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:55:09 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 21:04:45 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->map.width * SPRITE_SIZE, \
		game->map.height * SPRITE_SIZE, "so_long");
	game->player.direction = PLAYER_RIGHT;//posição inicial do player
	game->player.steps = 0;//passos do player
}
