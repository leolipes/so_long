/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:59:28 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 20:52:04 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			if (game->map.layout[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
