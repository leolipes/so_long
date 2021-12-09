/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:54:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/09 19:44:32 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectible(t_game *game)//checa se onde andei tem um coletável
{
	if(game->map.layout[game->player.y][game->player.x] == COLLECT)//se tiver coletável
	{
		game->map.layout[game->player.y][game->player.x] = FLOOR;//tiramos ele do mapa
	}
}

void	check_exit(t_game *game)
{
	int	x;
	int	y;
	int	has_collect;

	x = 0;
	y = 0;
	has_collect = 0;
	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			if(game->map.layout[y][x] == COLLECT)
				has_collect = 1;
			x++;
		}
		x = 0;
		y++;
	}
	if(has_collect == 0)
		game->is_open = 1;
}