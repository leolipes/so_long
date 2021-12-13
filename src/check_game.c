/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:54:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/11 20:30:20 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 4)
	{
		printf("this map does not have the .ber extension!\n");
		return (0);
	}
	if (file_name[i - 4] == '.' && file_name[i - 3] == 'b' \
		&& file_name[i - 2] == 'e' && file_name[i - 1] == 'r')
		return (1);
	printf("this map does not have the .ber extension!\n");
	return (0);
}

void	check_collectible(t_game *game)
{
	if (game->map.layout[game->player.y][game->player.x] == COLLECT)
	{
		game->map.layout[game->player.y][game->player.x] = FLOOR;
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
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.layout[y][x] == COLLECT)
				has_collect = 1;
			x++;
		}
		x = 0;
		y++;
	}
	if (has_collect == 0)
		game->is_open = 1;
}
